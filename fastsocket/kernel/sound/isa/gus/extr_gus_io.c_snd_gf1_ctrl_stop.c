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
struct snd_gus_card {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __snd_gf1_ctrl_stop (struct snd_gus_card*,unsigned char) ; 

void snd_gf1_ctrl_stop(struct snd_gus_card * gus, unsigned char reg)
{
	__snd_gf1_ctrl_stop(gus, reg);
}