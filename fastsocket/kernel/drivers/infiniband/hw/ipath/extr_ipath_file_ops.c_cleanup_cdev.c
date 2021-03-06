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
struct device {int dummy; } ;
struct cdev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cdev_del (struct cdev*) ; 
 int /*<<< orphan*/  device_unregister (struct device*) ; 

__attribute__((used)) static void cleanup_cdev(struct cdev **cdevp,
			 struct device **devp)
{
	struct device *dev = *devp;

	if (dev) {
		device_unregister(dev);
		*devp = NULL;
	}

	if (*cdevp) {
		cdev_del(*cdevp);
		*cdevp = NULL;
	}
}