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
struct usb_mixer_interface {int dummy; } ;
struct snd_device {struct usb_mixer_interface* device_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_usb_mixer_free (struct usb_mixer_interface*) ; 

__attribute__((used)) static int snd_usb_mixer_dev_free(struct snd_device *device)
{
	struct usb_mixer_interface *mixer = device->device_data;
	snd_usb_mixer_free(mixer);
	return 0;
}