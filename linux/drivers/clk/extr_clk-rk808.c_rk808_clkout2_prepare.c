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
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int rk808_clkout2_enable (struct clk_hw*,int) ; 

__attribute__((used)) static int rk808_clkout2_prepare(struct clk_hw *hw)
{
	return rk808_clkout2_enable(hw, true);
}