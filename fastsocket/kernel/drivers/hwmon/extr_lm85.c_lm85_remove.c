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
struct lm85_data {scalar_t__ type; int /*<<< orphan*/  hwmon_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {TYPE_1__ dev; } ;

/* Variables and functions */
 scalar_t__ emc6d100 ; 
 int /*<<< orphan*/  hwmon_device_unregister (int /*<<< orphan*/ ) ; 
 struct lm85_data* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  kfree (struct lm85_data*) ; 
 int /*<<< orphan*/  lm85_group ; 
 int /*<<< orphan*/  lm85_group_in4 ; 
 int /*<<< orphan*/  lm85_group_in567 ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int lm85_remove(struct i2c_client *client)
{
	struct lm85_data *data = i2c_get_clientdata(client);
	hwmon_device_unregister(data->hwmon_dev);
	sysfs_remove_group(&client->dev.kobj, &lm85_group);
	sysfs_remove_group(&client->dev.kobj, &lm85_group_in4);
	if (data->type == emc6d100)
		sysfs_remove_group(&client->dev.kobj, &lm85_group_in567);
	kfree(data);
	return 0;
}