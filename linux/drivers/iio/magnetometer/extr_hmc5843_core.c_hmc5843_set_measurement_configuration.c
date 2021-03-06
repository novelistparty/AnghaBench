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
struct iio_dev {int dummy; } ;
struct iio_chan_spec {int dummy; } ;
struct hmc5843_data {int dummy; } ;

/* Variables and functions */
 int hmc5843_set_meas_conf (struct hmc5843_data*,unsigned int) ; 
 struct hmc5843_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static
int hmc5843_set_measurement_configuration(struct iio_dev *indio_dev,
					  const struct iio_chan_spec *chan,
					  unsigned int meas_conf)
{
	struct hmc5843_data *data = iio_priv(indio_dev);

	return hmc5843_set_meas_conf(data, meas_conf);
}