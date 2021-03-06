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
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RLC_CNTL ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cik_enable_gui_idle_interrupt (struct radeon_device*,int) ; 
 int /*<<< orphan*/  cik_wait_for_rlc_serdes (struct radeon_device*) ; 

__attribute__((used)) static void cik_rlc_stop(struct radeon_device *rdev)
{
	WREG32(RLC_CNTL, 0);

	cik_enable_gui_idle_interrupt(rdev, false);

	cik_wait_for_rlc_serdes(rdev);
}