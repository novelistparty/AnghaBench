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
struct pcf50633_bl {int brightness; } ;
struct backlight_device {int dummy; } ;

/* Variables and functions */
 struct pcf50633_bl* bl_get_data (struct backlight_device*) ; 

__attribute__((used)) static int pcf50633_bl_get_brightness(struct backlight_device *bl)
{
	struct pcf50633_bl *pcf_bl = bl_get_data(bl);

	return pcf_bl->brightness;
}