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
struct sensor_device_attribute_2 {int nr; int index; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct adt7475_data {int alarms; unsigned short** voltage; int /*<<< orphan*/  bypass_attn; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
#define  ALARM 128 
 scalar_t__ IS_ERR (struct adt7475_data*) ; 
 int /*<<< orphan*/  PTR_ERR (struct adt7475_data*) ; 
 struct adt7475_data* adt7475_update_device (struct device*) ; 
 int reg2volt (size_t,unsigned short,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct sensor_device_attribute_2* to_sensor_dev_attr_2 (struct device_attribute*) ; 

__attribute__((used)) static ssize_t voltage_show(struct device *dev, struct device_attribute *attr,
			    char *buf)
{
	struct adt7475_data *data = adt7475_update_device(dev);
	struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
	unsigned short val;

	if (IS_ERR(data))
		return PTR_ERR(data);

	switch (sattr->nr) {
	case ALARM:
		return sprintf(buf, "%d\n",
			       (data->alarms >> sattr->index) & 1);
	default:
		val = data->voltage[sattr->nr][sattr->index];
		return sprintf(buf, "%d\n",
			       reg2volt(sattr->index, val, data->bypass_attn));
	}
}