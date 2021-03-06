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
typedef  int u8 ;
struct lm93_data {int** block9; int /*<<< orphan*/  update_lock; struct i2c_client* client; } ;
struct i2c_client {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_2__ {int index; } ;

/* Variables and functions */
 size_t LM93_PWM_CTL4 ; 
 int LM93_PWM_FREQ_TO_REG (unsigned long) ; 
 int /*<<< orphan*/  LM93_REG_PWM_CTL (int,size_t) ; 
 struct lm93_data* dev_get_drvdata (struct device*) ; 
 int kstrtoul (char const*,int,unsigned long*) ; 
 int /*<<< orphan*/  lm93_disable_fan_smart_tach (struct i2c_client*,struct lm93_data*,int) ; 
 int lm93_read_byte (struct i2c_client*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lm93_write_byte (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 TYPE_1__* to_sensor_dev_attr (struct device_attribute*) ; 

__attribute__((used)) static ssize_t pwm_freq_store(struct device *dev,
			      struct device_attribute *attr, const char *buf,
			      size_t count)
{
	int nr = (to_sensor_dev_attr(attr))->index;
	struct lm93_data *data = dev_get_drvdata(dev);
	struct i2c_client *client = data->client;
	u8 ctl4;
	unsigned long val;
	int err;

	err = kstrtoul(buf, 10, &val);
	if (err)
		return err;

	mutex_lock(&data->update_lock);
	ctl4 = lm93_read_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4));
	ctl4 = (ctl4 & 0xf8) | LM93_PWM_FREQ_TO_REG(val);
	data->block9[nr][LM93_PWM_CTL4] = ctl4;
	/* ctl4 == 0 -> 22.5KHz -> disable smart tach */
	if (!ctl4)
		lm93_disable_fan_smart_tach(client, data, nr);
	lm93_write_byte(client, LM93_REG_PWM_CTL(nr, LM93_PWM_CTL4), ctl4);
	mutex_unlock(&data->update_lock);
	return count;
}