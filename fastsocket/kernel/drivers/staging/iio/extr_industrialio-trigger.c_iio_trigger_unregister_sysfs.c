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
struct iio_trigger {scalar_t__ control_attrs; TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,scalar_t__) ; 

__attribute__((used)) static void iio_trigger_unregister_sysfs(struct iio_trigger *trig_info)
{
	if (trig_info->control_attrs)
		sysfs_remove_group(&trig_info->dev.kobj,
				   trig_info->control_attrs);
}