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
 scalar_t__ MCDT_DAC_DMA_SHIFT ; 
 int /*<<< orphan*/  MCDT_DMA_EN ; 
 int /*<<< orphan*/  sprd_mcdt_update (struct sprd_mcdt_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sprd_mcdt_dac_dma_enable(struct sprd_mcdt_dev *mcdt, u8 channel,
				     bool enable)
{
	u32 shift = MCDT_DAC_DMA_SHIFT + channel;

	if (enable)
		sprd_mcdt_update(mcdt, MCDT_DMA_EN, BIT(shift), BIT(shift));
	else
		sprd_mcdt_update(mcdt, MCDT_DMA_EN, 0, BIT(shift));
}