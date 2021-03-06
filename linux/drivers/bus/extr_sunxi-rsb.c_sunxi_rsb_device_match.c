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
struct device_driver {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int of_driver_match_device (struct device*,struct device_driver*) ; 

__attribute__((used)) static int sunxi_rsb_device_match(struct device *dev, struct device_driver *drv)
{
	return of_driver_match_device(dev, drv);
}