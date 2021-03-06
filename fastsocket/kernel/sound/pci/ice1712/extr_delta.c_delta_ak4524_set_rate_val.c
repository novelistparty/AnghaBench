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
struct snd_ice1712 {int /*<<< orphan*/  gpio_mutex; } ;
struct snd_akm4xxx {struct snd_ice1712** private_data; } ;

/* Variables and functions */
 unsigned char ICE1712_DELTA_DFS ; 
 int /*<<< orphan*/  ICE1712_IREG_GPIO_DATA ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_akm4xxx_reset (struct snd_akm4xxx*,int) ; 
 unsigned char snd_ice1712_read (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ice1712_write (struct snd_ice1712*,int /*<<< orphan*/ ,unsigned char) ; 

__attribute__((used)) static void delta_ak4524_set_rate_val(struct snd_akm4xxx *ak, unsigned int rate)
{
	unsigned char tmp, tmp2;
	struct snd_ice1712 *ice = ak->private_data[0];

	if (rate == 0)	/* no hint - S/PDIF input is master, simply return */
		return;

	/* check before reset ak4524 to avoid unnecessary clicks */
	mutex_lock(&ice->gpio_mutex);
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA);
	mutex_unlock(&ice->gpio_mutex);
	tmp2 = tmp & ~ICE1712_DELTA_DFS; 
	if (rate > 48000)
		tmp2 |= ICE1712_DELTA_DFS;
	if (tmp == tmp2)
		return;

	/* do it again */
	snd_akm4xxx_reset(ak, 1);
	mutex_lock(&ice->gpio_mutex);
	tmp = snd_ice1712_read(ice, ICE1712_IREG_GPIO_DATA) & ~ICE1712_DELTA_DFS;
	if (rate > 48000)
		tmp |= ICE1712_DELTA_DFS;
	snd_ice1712_write(ice, ICE1712_IREG_GPIO_DATA, tmp);
	mutex_unlock(&ice->gpio_mutex);
	snd_akm4xxx_reset(ak, 0);
}