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
typedef  int /*<<< orphan*/  u32 ;
struct radeon_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CG_MPLL_SPREAD_SPECTRUM ; 
 int /*<<< orphan*/  CLKS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLKS_MASK ; 
 int /*<<< orphan*/  WREG32_P (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rv6xx_set_memory_spread_spectrum_clk_s(struct radeon_device *rdev,
						   u32 clk_s)
{
	WREG32_P(CG_MPLL_SPREAD_SPECTRUM, CLKS(clk_s), ~CLKS_MASK);
}