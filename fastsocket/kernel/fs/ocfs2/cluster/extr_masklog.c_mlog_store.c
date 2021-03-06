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
struct mlog_attribute {int /*<<< orphan*/  mask; } ;
struct kobject {int dummy; } ;
struct attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  mlog_mask_store (int /*<<< orphan*/ ,char const*,size_t) ; 
 struct mlog_attribute* to_mlog_attr (struct attribute*) ; 

__attribute__((used)) static ssize_t mlog_store(struct kobject *obj, struct attribute *attr,
			  const char *buf, size_t count)
{
	struct mlog_attribute *mlog_attr = to_mlog_attr(attr);

	return mlog_mask_store(mlog_attr->mask, buf, count);
}