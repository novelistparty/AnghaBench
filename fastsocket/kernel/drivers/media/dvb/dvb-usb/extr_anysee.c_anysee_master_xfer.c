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
typedef  int u8 ;
struct i2c_msg {int flags; int addr; int* buf; int len; } ;
struct i2c_adapter {int dummy; } ;
struct dvb_usb_device {int /*<<< orphan*/  i2c_mutex; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int CMD_I2C_READ ; 
 int CMD_I2C_WRITE ; 
 int EAGAIN ; 
 int I2C_M_RD ; 
 int anysee_ctrl_msg (struct dvb_usb_device*,int*,int,int*,int) ; 
 struct dvb_usb_device* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 scalar_t__ mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int anysee_master_xfer(struct i2c_adapter *adap, struct i2c_msg *msg,
	int num)
{
	struct dvb_usb_device *d = i2c_get_adapdata(adap);
	int ret = 0, inc, i = 0;

	if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
		return -EAGAIN;

	while (i < num) {
		if (num > i + 1 && (msg[i+1].flags & I2C_M_RD)) {
			u8 buf[6];
			buf[0] = CMD_I2C_READ;
			buf[1] = msg[i].addr + 1;
			buf[2] = msg[i].buf[0];
			buf[3] = 0x00;
			buf[4] = 0x00;
			buf[5] = 0x01;
			ret = anysee_ctrl_msg(d, buf, sizeof(buf), msg[i+1].buf,
				msg[i+1].len);
			inc = 2;
		} else {
			u8 buf[4+msg[i].len];
			buf[0] = CMD_I2C_WRITE;
			buf[1] = msg[i].addr;
			buf[2] = msg[i].len;
			buf[3] = 0x01;
			memcpy(&buf[4], msg[i].buf, msg[i].len);
			ret = anysee_ctrl_msg(d, buf, sizeof(buf), NULL, 0);
			inc = 1;
		}
		if (ret)
			break;

		i += inc;
	}

	mutex_unlock(&d->i2c_mutex);

	return ret ? ret : i;
}