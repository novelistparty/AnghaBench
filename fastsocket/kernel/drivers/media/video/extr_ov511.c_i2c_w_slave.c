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
struct usb_ov511 {unsigned char primary_i2c_slave; int /*<<< orphan*/  i2c_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  err (char*) ; 
 int i2c_set_slave_internal (struct usb_ov511*,unsigned char) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int ov51x_i2c_write_mask_internal (struct usb_ov511*,unsigned char,unsigned char,unsigned char) ; 

__attribute__((used)) static int
i2c_w_slave(struct usb_ov511 *ov,
	    unsigned char slave,
	    unsigned char reg,
	    unsigned char value,
	    unsigned char mask)
{
	int rc = 0;

	mutex_lock(&ov->i2c_lock);

	/* Set new slave IDs */
	rc = i2c_set_slave_internal(ov, slave);
	if (rc < 0)
		goto out;

	rc = ov51x_i2c_write_mask_internal(ov, reg, value, mask);

out:
	/* Restore primary IDs */
	if (i2c_set_slave_internal(ov, ov->primary_i2c_slave) < 0)
		err("Couldn't restore primary I2C slave");

	mutex_unlock(&ov->i2c_lock);
	return rc;
}