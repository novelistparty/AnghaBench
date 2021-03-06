#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* ports_parent; } ;
struct mlx4_ib_dev {TYPE_2__ ib_dev; int /*<<< orphan*/  iov_parent; int /*<<< orphan*/  ports_parent; } ;
struct TYPE_3__ {int /*<<< orphan*/  parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  kobject_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unregister_alias_guid_tree (struct mlx4_ib_dev*) ; 
 int /*<<< orphan*/  unregister_pkey_tree (struct mlx4_ib_dev*) ; 

void mlx4_ib_device_unregister_sysfs(struct mlx4_ib_dev *device)
{
	unregister_alias_guid_tree(device);
	unregister_pkey_tree(device);
	kobject_put(device->ports_parent);
	kobject_put(device->iov_parent);
	kobject_put(device->iov_parent);
	kobject_put(device->ib_dev.ports_parent->parent);
}