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
struct fb_info {int /*<<< orphan*/  flags; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  FBINFO_MISC_USEREVENT ; 
 int /*<<< orphan*/  acquire_console_sem () ; 
 struct fb_info* dev_get_drvdata (struct device*) ; 
 int fb_blank (struct fb_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_console_sem () ; 
 int /*<<< orphan*/  simple_strtoul (char const*,char**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t store_blank(struct device *device,
			   struct device_attribute *attr,
			   const char *buf, size_t count)
{
	struct fb_info *fb_info = dev_get_drvdata(device);
	char *last = NULL;
	int err;

	acquire_console_sem();
	fb_info->flags |= FBINFO_MISC_USEREVENT;
	err = fb_blank(fb_info, simple_strtoul(buf, &last, 0));
	fb_info->flags &= ~FBINFO_MISC_USEREVENT;
	release_console_sem();
	if (err < 0)
		return err;
	return count;
}