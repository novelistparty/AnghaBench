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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
struct sprd_mcdt_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (scalar_t__) ; 
 scalar_t__ MCDT_ADC_FIFO_SHIFT ; 
 int /*<<< orphan*/  MCDT_FIFO_CLR ; 
 int /*<<< orphan*/  sprd_mcdt_update (struct sprd_mcdt_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sprd_mcdt_adc_fifo_clear(struct sprd_mcdt_dev *mcdt, u8 channel)
{
	u32 shift = MCDT_ADC_FIFO_SHIFT + channel;

	sprd_mcdt_update(mcdt, MCDT_FIFO_CLR, BIT(shift), BIT(shift));
}