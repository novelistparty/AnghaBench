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
struct soundbus_driver {int /*<<< orphan*/  (* remove ) (struct soundbus_dev*) ;} ;
struct soundbus_dev {int dummy; } ;
struct device {scalar_t__ driver; } ;

/* Variables and functions */
 int /*<<< orphan*/  soundbus_dev_put (struct soundbus_dev*) ; 
 int /*<<< orphan*/  stub1 (struct soundbus_dev*) ; 
 struct soundbus_dev* to_soundbus_device (struct device*) ; 
 struct soundbus_driver* to_soundbus_driver (scalar_t__) ; 

__attribute__((used)) static int soundbus_device_remove(struct device *dev)
{
	struct soundbus_dev * soundbus_dev = to_soundbus_device(dev);
	struct soundbus_driver * drv = to_soundbus_driver(dev->driver);

	if (dev->driver && drv->remove)
		drv->remove(soundbus_dev);
	soundbus_dev_put(soundbus_dev);

	return 0;
}