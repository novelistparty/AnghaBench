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
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {struct snd_cs46xx_pcm* private_data; } ;
struct snd_cs46xx_pcm {int /*<<< orphan*/  pcm_rec; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_cs46xx_pb_trans_copy ; 
 int snd_pcm_indirect_playback_transfer (struct snd_pcm_substream*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_cs46xx_playback_transfer(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct snd_cs46xx_pcm * cpcm = runtime->private_data;
	return snd_pcm_indirect_playback_transfer(substream, &cpcm->pcm_rec,
						  snd_cs46xx_pb_trans_copy);
}