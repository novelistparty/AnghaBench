#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct snd_soc_component {int dummy; } ;
struct bd28623_priv {scalar_t__ switch_spk; int /*<<< orphan*/  mute_gpio; } ;

/* Variables and functions */
 int bd28623_power_on (struct bd28623_priv*) ; 
 int /*<<< orphan*/  gpiod_set_value_cansleep (int /*<<< orphan*/ ,int) ; 
 struct bd28623_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int bd28623_codec_resume(struct snd_soc_component *component)
{
	struct bd28623_priv *bd = snd_soc_component_get_drvdata(component);
	int ret;

	ret = bd28623_power_on(bd);
	if (ret)
		return ret;

	gpiod_set_value_cansleep(bd->mute_gpio, bd->switch_spk ? 0 : 1);

	return 0;
}