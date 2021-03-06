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
struct clk_zx_pll {int /*<<< orphan*/  pd_bit; int /*<<< orphan*/  reg_base; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int readl_relaxed (int /*<<< orphan*/ ) ; 
 struct clk_zx_pll* to_clk_zx_pll (struct clk_hw*) ; 

__attribute__((used)) static int zx_pll_is_enabled(struct clk_hw *hw)
{
	struct clk_zx_pll *zx_pll = to_clk_zx_pll(hw);
	u32 reg;

	reg = readl_relaxed(zx_pll->reg_base);

	return !(reg & BIT(zx_pll->pd_bit));
}