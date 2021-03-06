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
struct iio_dev {int /*<<< orphan*/  dev; } ;
struct adis16400_state {int /*<<< orphan*/  adis; } ;

/* Variables and functions */
 int /*<<< orphan*/  ADIS16400_SLP_CNT ; 
 int /*<<< orphan*/  ADIS16400_SLP_CNT_POWER_OFF ; 
 int adis_write_reg_16 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 struct adis16400_state* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int adis16400_stop_device(struct iio_dev *indio_dev)
{
	struct adis16400_state *st = iio_priv(indio_dev);
	int ret;

	ret = adis_write_reg_16(&st->adis, ADIS16400_SLP_CNT,
			ADIS16400_SLP_CNT_POWER_OFF);
	if (ret)
		dev_err(&indio_dev->dev,
			"problem with turning device off: SLP_CNT");

	return ret;
}