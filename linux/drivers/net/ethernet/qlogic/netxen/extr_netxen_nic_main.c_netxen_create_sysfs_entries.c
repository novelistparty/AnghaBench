#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct netxen_adapter {int capabilities; TYPE_1__* pdev; } ;
struct device {int dummy; } ;
struct TYPE_2__ {struct device dev; } ;

/* Variables and functions */
 int NX_FW_CAPABILITY_BDG ; 
 int /*<<< orphan*/  dev_attr_bridged_mode ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 scalar_t__ device_create_file (struct device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
netxen_create_sysfs_entries(struct netxen_adapter *adapter)
{
	struct device *dev = &adapter->pdev->dev;

	if (adapter->capabilities & NX_FW_CAPABILITY_BDG) {
		/* bridged_mode control */
		if (device_create_file(dev, &dev_attr_bridged_mode)) {
			dev_warn(dev,
				"failed to create bridged_mode sysfs entry\n");
		}
	}
}