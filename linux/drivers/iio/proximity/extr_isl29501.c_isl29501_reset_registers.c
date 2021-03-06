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
struct isl29501_private {TYPE_1__* client; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ISL29501_COMMAND_REGISTER ; 
 int /*<<< orphan*/  ISL29501_RESET_ALL_REGISTERS ; 
 int /*<<< orphan*/  ISL29501_RESET_INT_SM ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int i2c_smbus_write_byte_data (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int isl29501_reset_registers(struct isl29501_private *isl29501)
{
	int ret;

	ret = i2c_smbus_write_byte_data(isl29501->client,
					ISL29501_COMMAND_REGISTER,
					ISL29501_RESET_ALL_REGISTERS);
	if (ret < 0) {
		dev_err(&isl29501->client->dev,
			"cannot reset registers %d\n", ret);
		return ret;
	}

	ret = i2c_smbus_write_byte_data(isl29501->client,
					ISL29501_COMMAND_REGISTER,
					ISL29501_RESET_INT_SM);
	if (ret < 0)
		dev_err(&isl29501->client->dev,
			"cannot reset state machine %d\n", ret);

	return ret;
}