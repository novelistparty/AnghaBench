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
struct lm87_data {int /*<<< orphan*/ * in_scale; int /*<<< orphan*/ * in; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 int IN_FROM_REG (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct lm87_data* lm87_update_device (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t in_input_show(struct device *dev,
			     struct device_attribute *attr, char *buf)
{
	struct lm87_data *data = lm87_update_device(dev);
	int nr = to_sensor_dev_attr(attr)->index;

	return sprintf(buf, "%u\n", IN_FROM_REG(data->in[nr],
		       data->in_scale[nr]));
}