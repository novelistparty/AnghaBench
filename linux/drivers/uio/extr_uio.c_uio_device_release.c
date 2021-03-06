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
struct uio_device {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct uio_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  kfree (struct uio_device*) ; 

__attribute__((used)) static void uio_device_release(struct device *dev)
{
	struct uio_device *idev = dev_get_drvdata(dev);

	kfree(idev);
}