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
struct TYPE_2__ {int /*<<< orphan*/  kobj; } ;
struct rio_dev {TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  rio_config_attr ; 
 int sysfs_create_bin_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int rio_create_sysfs_dev_files(struct rio_dev *rdev)
{
	int err = 0;

	err = sysfs_create_bin_file(&rdev->dev.kobj, &rio_config_attr);

	return err;
}