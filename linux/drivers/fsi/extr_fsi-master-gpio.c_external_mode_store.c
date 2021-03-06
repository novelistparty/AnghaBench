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
struct fsi_master_gpio {int external_mode; int /*<<< orphan*/  master; int /*<<< orphan*/  cmd_lock; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 struct fsi_master_gpio* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  fsi_master_gpio_init (struct fsi_master_gpio*) ; 
 int /*<<< orphan*/  fsi_master_gpio_init_external (struct fsi_master_gpio*) ; 
 int /*<<< orphan*/  fsi_master_rescan (int /*<<< orphan*/ *) ; 
 int kstrtoul (char const*,int /*<<< orphan*/ ,unsigned long*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t external_mode_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	struct fsi_master_gpio *master = dev_get_drvdata(dev);
	unsigned long val;
	bool external_mode;
	int err;

	err = kstrtoul(buf, 0, &val);
	if (err)
		return err;

	external_mode = !!val;

	mutex_lock(&master->cmd_lock);

	if (external_mode == master->external_mode) {
		mutex_unlock(&master->cmd_lock);
		return count;
	}

	master->external_mode = external_mode;
	if (master->external_mode)
		fsi_master_gpio_init_external(master);
	else
		fsi_master_gpio_init(master);

	mutex_unlock(&master->cmd_lock);

	fsi_master_rescan(&master->master);

	return count;
}