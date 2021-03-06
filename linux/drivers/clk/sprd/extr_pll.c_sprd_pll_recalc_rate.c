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
struct sprd_pll {int dummy; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 unsigned long _sprd_pll_recalc_rate (struct sprd_pll*,unsigned long) ; 
 struct sprd_pll* hw_to_sprd_pll (struct clk_hw*) ; 

__attribute__((used)) static unsigned long sprd_pll_recalc_rate(struct clk_hw *hw,
					  unsigned long parent_rate)
{
	struct sprd_pll *pll = hw_to_sprd_pll(hw);

	return _sprd_pll_recalc_rate(pll, parent_rate);
}