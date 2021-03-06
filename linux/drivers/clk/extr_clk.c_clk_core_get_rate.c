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
struct clk_core {int flags; } ;

/* Variables and functions */
 int CLK_GET_RATE_NOCACHE ; 
 int /*<<< orphan*/  __clk_recalc_rates (struct clk_core*,int /*<<< orphan*/ ) ; 
 unsigned long clk_core_get_rate_nolock (struct clk_core*) ; 
 int /*<<< orphan*/  clk_prepare_lock () ; 
 int /*<<< orphan*/  clk_prepare_unlock () ; 

__attribute__((used)) static unsigned long clk_core_get_rate(struct clk_core *core)
{
	unsigned long rate;

	clk_prepare_lock();

	if (core && (core->flags & CLK_GET_RATE_NOCACHE))
		__clk_recalc_rates(core, 0);

	rate = clk_core_get_rate_nolock(core);
	clk_prepare_unlock();

	return rate;
}