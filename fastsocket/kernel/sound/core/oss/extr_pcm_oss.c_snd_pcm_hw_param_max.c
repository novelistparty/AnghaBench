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
struct snd_pcm_substream {int dummy; } ;
struct snd_pcm_hw_params {scalar_t__ rmask; } ;
typedef  int /*<<< orphan*/  snd_pcm_hw_param_t ;

/* Variables and functions */
 int _snd_pcm_hw_param_max (struct snd_pcm_hw_params*,int /*<<< orphan*/ ,unsigned int,int) ; 
 int snd_pcm_hw_param_value_max (struct snd_pcm_hw_params*,int /*<<< orphan*/ ,int*) ; 
 int snd_pcm_hw_refine (struct snd_pcm_substream*,struct snd_pcm_hw_params*) ; 

__attribute__((used)) static int snd_pcm_hw_param_max(struct snd_pcm_substream *pcm,
				struct snd_pcm_hw_params *params,
				snd_pcm_hw_param_t var, unsigned int val,
				int *dir)
{
	int changed = _snd_pcm_hw_param_max(params, var, val, dir ? *dir : 0);
	if (changed < 0)
		return changed;
	if (params->rmask) {
		int err = snd_pcm_hw_refine(pcm, params);
		if (err < 0)
			return err;
	}
	return snd_pcm_hw_param_value_max(params, var, dir);
}