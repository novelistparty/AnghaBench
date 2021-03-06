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
struct snd_rawmidi {struct snd_msndmidi* private_data; } ;
struct snd_msndmidi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct snd_msndmidi*) ; 

__attribute__((used)) static void snd_msndmidi_free(struct snd_rawmidi *rmidi)
{
	struct snd_msndmidi *mpu = rmidi->private_data;
	kfree(mpu);
}