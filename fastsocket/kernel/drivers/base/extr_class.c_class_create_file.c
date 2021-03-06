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
struct class_attribute {int /*<<< orphan*/  attr; } ;
struct class {TYPE_2__* p; } ;
struct TYPE_3__ {int /*<<< orphan*/  kobj; } ;
struct TYPE_4__ {TYPE_1__ class_subsys; } ;

/* Variables and functions */
 int EINVAL ; 
 int sysfs_create_file (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int class_create_file(struct class *cls, const struct class_attribute *attr)
{
	int error;
	if (cls)
		error = sysfs_create_file(&cls->p->class_subsys.kobj,
					  &attr->attr);
	else
		error = -EINVAL;
	return error;
}