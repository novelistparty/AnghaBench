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
struct ksz_hw {scalar_t__ io; } ;

/* Variables and functions */
 int /*<<< orphan*/  GLOBAL_SOFTWARE_RESET ; 
 scalar_t__ KS884X_GLOBAL_CTRL_OFFSET ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  writew (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void hw_reset(struct ksz_hw *hw)
{
	writew(GLOBAL_SOFTWARE_RESET, hw->io + KS884X_GLOBAL_CTRL_OFFSET);

	/* Wait for device to reset. */
	mdelay(10);

	/* Write 0 to clear device reset. */
	writew(0, hw->io + KS884X_GLOBAL_CTRL_OFFSET);
}