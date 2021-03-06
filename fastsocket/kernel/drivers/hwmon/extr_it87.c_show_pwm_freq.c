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
struct it87_data {int fan_ctl; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 struct it87_data* it87_update_device (struct device*) ; 
 int* pwm_freq ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t show_pwm_freq(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct it87_data *data = it87_update_device(dev);
	int index = (data->fan_ctl >> 4) & 0x07;

	return sprintf(buf, "%u\n", pwm_freq[index]);
}