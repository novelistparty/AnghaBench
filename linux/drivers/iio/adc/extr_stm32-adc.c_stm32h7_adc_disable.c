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
typedef  int u32 ;
struct stm32_adc {int dummy; } ;
struct iio_dev {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  STM32H7_ADC_CR ; 
 int /*<<< orphan*/  STM32H7_ADDIS ; 
 int STM32H7_ADEN ; 
 int /*<<< orphan*/  STM32_ADC_TIMEOUT_US ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct iio_dev* iio_priv_to_dev (struct stm32_adc*) ; 
 int stm32_adc_readl_poll_timeout (int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stm32_adc_set_bits (struct stm32_adc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void stm32h7_adc_disable(struct stm32_adc *adc)
{
	struct iio_dev *indio_dev = iio_priv_to_dev(adc);
	int ret;
	u32 val;

	/* Disable ADC and wait until it's effectively disabled */
	stm32_adc_set_bits(adc, STM32H7_ADC_CR, STM32H7_ADDIS);
	ret = stm32_adc_readl_poll_timeout(STM32H7_ADC_CR, val,
					   !(val & STM32H7_ADEN), 100,
					   STM32_ADC_TIMEOUT_US);
	if (ret)
		dev_warn(&indio_dev->dev, "Failed to disable\n");
}