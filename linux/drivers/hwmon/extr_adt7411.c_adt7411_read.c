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
typedef  int /*<<< orphan*/  u32 ;
struct device {int dummy; } ;
typedef  enum hwmon_sensor_types { ____Placeholder_hwmon_sensor_types } hwmon_sensor_types ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int adt7411_read_in (struct device*,int /*<<< orphan*/ ,int,long*) ; 
 int adt7411_read_temp (struct device*,int /*<<< orphan*/ ,int,long*) ; 
#define  hwmon_in 129 
#define  hwmon_temp 128 

__attribute__((used)) static int adt7411_read(struct device *dev, enum hwmon_sensor_types type,
			u32 attr, int channel, long *val)
{
	switch (type) {
	case hwmon_in:
		return adt7411_read_in(dev, attr, channel, val);
	case hwmon_temp:
		return adt7411_read_temp(dev, attr, channel, val);
	default:
		return -EOPNOTSUPP;
	}
}