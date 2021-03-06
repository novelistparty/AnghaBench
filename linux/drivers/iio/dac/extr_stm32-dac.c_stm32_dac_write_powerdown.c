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
struct iio_chan_spec {int /*<<< orphan*/  channel; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int stm32_dac_set_enable_state (struct iio_dev*,int /*<<< orphan*/ ,int) ; 
 int strtobool (char const*,int*) ; 

__attribute__((used)) static ssize_t stm32_dac_write_powerdown(struct iio_dev *indio_dev,
					 uintptr_t private,
					 const struct iio_chan_spec *chan,
					 const char *buf, size_t len)
{
	bool powerdown;
	int ret;

	ret = strtobool(buf, &powerdown);
	if (ret)
		return ret;

	ret = stm32_dac_set_enable_state(indio_dev, chan->channel, !powerdown);
	if (ret)
		return ret;

	return len;
}