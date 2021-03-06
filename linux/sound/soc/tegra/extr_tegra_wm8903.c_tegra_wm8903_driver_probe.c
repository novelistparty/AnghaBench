#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct tegra_wm8903 {int gpio_spkr_en; int gpio_hp_mute; int gpio_hp_det; int gpio_int_mic_en; int gpio_ext_mic_en; int /*<<< orphan*/  util_data; } ;
struct snd_soc_card {TYPE_5__* dev; } ;
struct TYPE_13__ {struct device_node* of_node; } ;
struct platform_device {TYPE_5__ dev; } ;
struct device_node {int dummy; } ;
struct TYPE_12__ {TYPE_3__* cpus; TYPE_2__* platforms; TYPE_1__* codecs; } ;
struct TYPE_11__ {void* of_node; } ;
struct TYPE_10__ {void* of_node; } ;
struct TYPE_9__ {void* of_node; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_HIGH ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*,...) ; 
 int devm_gpio_request_one (TYPE_5__*,int,int /*<<< orphan*/ ,char*) ; 
 struct tegra_wm8903* devm_kzalloc (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ gpio_is_valid (int) ; 
 void* of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 void* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_card_set_drvdata (struct snd_soc_card*,struct tegra_wm8903*) ; 
 int snd_soc_of_parse_audio_routing (struct snd_soc_card*,char*) ; 
 int snd_soc_of_parse_card_name (struct snd_soc_card*,char*) ; 
 int snd_soc_register_card (struct snd_soc_card*) ; 
 struct snd_soc_card snd_soc_tegra_wm8903 ; 
 int /*<<< orphan*/  tegra_asoc_utils_fini (int /*<<< orphan*/ *) ; 
 int tegra_asoc_utils_init (int /*<<< orphan*/ *,TYPE_5__*) ; 
 TYPE_4__ tegra_wm8903_dai ; 

__attribute__((used)) static int tegra_wm8903_driver_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct snd_soc_card *card = &snd_soc_tegra_wm8903;
	struct tegra_wm8903 *machine;
	int ret;

	machine = devm_kzalloc(&pdev->dev, sizeof(struct tegra_wm8903),
			       GFP_KERNEL);
	if (!machine)
		return -ENOMEM;

	card->dev = &pdev->dev;
	snd_soc_card_set_drvdata(card, machine);

	machine->gpio_spkr_en = of_get_named_gpio(np, "nvidia,spkr-en-gpios",
						  0);
	if (machine->gpio_spkr_en == -EPROBE_DEFER)
		return -EPROBE_DEFER;
	if (gpio_is_valid(machine->gpio_spkr_en)) {
		ret = devm_gpio_request_one(&pdev->dev, machine->gpio_spkr_en,
					    GPIOF_OUT_INIT_LOW, "spkr_en");
		if (ret) {
			dev_err(card->dev, "cannot get spkr_en gpio\n");
			return ret;
		}
	}

	machine->gpio_hp_mute = of_get_named_gpio(np, "nvidia,hp-mute-gpios",
						  0);
	if (machine->gpio_hp_mute == -EPROBE_DEFER)
		return -EPROBE_DEFER;
	if (gpio_is_valid(machine->gpio_hp_mute)) {
		ret = devm_gpio_request_one(&pdev->dev, machine->gpio_hp_mute,
					    GPIOF_OUT_INIT_HIGH, "hp_mute");
		if (ret) {
			dev_err(card->dev, "cannot get hp_mute gpio\n");
			return ret;
		}
	}

	machine->gpio_hp_det = of_get_named_gpio(np, "nvidia,hp-det-gpios", 0);
	if (machine->gpio_hp_det == -EPROBE_DEFER)
		return -EPROBE_DEFER;

	machine->gpio_int_mic_en = of_get_named_gpio(np,
						"nvidia,int-mic-en-gpios", 0);
	if (machine->gpio_int_mic_en == -EPROBE_DEFER)
		return -EPROBE_DEFER;
	if (gpio_is_valid(machine->gpio_int_mic_en)) {
		/* Disable int mic; enable signal is active-high */
		ret = devm_gpio_request_one(&pdev->dev,
					    machine->gpio_int_mic_en,
					    GPIOF_OUT_INIT_LOW, "int_mic_en");
		if (ret) {
			dev_err(card->dev, "cannot get int_mic_en gpio\n");
			return ret;
		}
	}

	machine->gpio_ext_mic_en = of_get_named_gpio(np,
						"nvidia,ext-mic-en-gpios", 0);
	if (machine->gpio_ext_mic_en == -EPROBE_DEFER)
		return -EPROBE_DEFER;
	if (gpio_is_valid(machine->gpio_ext_mic_en)) {
		/* Enable ext mic; enable signal is active-low */
		ret = devm_gpio_request_one(&pdev->dev,
					    machine->gpio_ext_mic_en,
					    GPIOF_OUT_INIT_LOW, "ext_mic_en");
		if (ret) {
			dev_err(card->dev, "cannot get ext_mic_en gpio\n");
			return ret;
		}
	}

	ret = snd_soc_of_parse_card_name(card, "nvidia,model");
	if (ret)
		goto err;

	ret = snd_soc_of_parse_audio_routing(card, "nvidia,audio-routing");
	if (ret)
		goto err;

	tegra_wm8903_dai.codecs->of_node = of_parse_phandle(np,
						"nvidia,audio-codec", 0);
	if (!tegra_wm8903_dai.codecs->of_node) {
		dev_err(&pdev->dev,
			"Property 'nvidia,audio-codec' missing or invalid\n");
		ret = -EINVAL;
		goto err;
	}

	tegra_wm8903_dai.cpus->of_node = of_parse_phandle(np,
			"nvidia,i2s-controller", 0);
	if (!tegra_wm8903_dai.cpus->of_node) {
		dev_err(&pdev->dev,
			"Property 'nvidia,i2s-controller' missing or invalid\n");
		ret = -EINVAL;
		goto err;
	}

	tegra_wm8903_dai.platforms->of_node = tegra_wm8903_dai.cpus->of_node;

	ret = tegra_asoc_utils_init(&machine->util_data, &pdev->dev);
	if (ret)
		goto err;

	ret = snd_soc_register_card(card);
	if (ret) {
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
			ret);
		goto err_fini_utils;
	}

	return 0;

err_fini_utils:
	tegra_asoc_utils_fini(&machine->util_data);
err:
	return ret;
}