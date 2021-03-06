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
typedef  int /*<<< orphan*/  snd_pcm_format_t ;

/* Variables and functions */
 unsigned int TDM_CHANNEL_BCK_16 ; 
 unsigned int TDM_CHANNEL_BCK_32 ; 
 int snd_pcm_format_physical_width (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int get_tdm_channel_bck(snd_pcm_format_t format)
{
	return snd_pcm_format_physical_width(format) <= 16 ?
	       TDM_CHANNEL_BCK_16 : TDM_CHANNEL_BCK_32;
}