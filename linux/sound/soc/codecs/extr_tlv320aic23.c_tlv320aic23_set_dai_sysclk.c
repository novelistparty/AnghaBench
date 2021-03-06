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
struct snd_soc_dai {int dummy; } ;
struct aic23 {unsigned int mclk; } ;

/* Variables and functions */
 struct aic23* snd_soc_dai_get_drvdata (struct snd_soc_dai*) ; 

__attribute__((used)) static int tlv320aic23_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				      int clk_id, unsigned int freq, int dir)
{
	struct aic23 *aic23 = snd_soc_dai_get_drvdata(codec_dai);
	aic23->mclk = freq;
	return 0;
}