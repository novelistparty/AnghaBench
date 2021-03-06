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
struct dw_i2c_dev {scalar_t__ sda_hold_time; } ;

/* Variables and functions */
 int /*<<< orphan*/  DW_IC_SDA_HOLD ; 
 int /*<<< orphan*/  __i2c_dw_disable (struct dw_i2c_dev*) ; 
 int /*<<< orphan*/  dw_writel (struct dw_i2c_dev*,scalar_t__,int /*<<< orphan*/ ) ; 
 int i2c_dw_acquire_lock (struct dw_i2c_dev*) ; 
 int /*<<< orphan*/  i2c_dw_configure_fifo_slave (struct dw_i2c_dev*) ; 
 int /*<<< orphan*/  i2c_dw_release_lock (struct dw_i2c_dev*) ; 

__attribute__((used)) static int i2c_dw_init_slave(struct dw_i2c_dev *dev)
{
	int ret;

	ret = i2c_dw_acquire_lock(dev);
	if (ret)
		return ret;

	/* Disable the adapter. */
	__i2c_dw_disable(dev);

	/* Write SDA hold time if supported */
	if (dev->sda_hold_time)
		dw_writel(dev, dev->sda_hold_time, DW_IC_SDA_HOLD);

	i2c_dw_configure_fifo_slave(dev);
	i2c_dw_release_lock(dev);

	return 0;
}