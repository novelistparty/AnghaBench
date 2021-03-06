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
typedef  int /*<<< orphan*/  uint ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_STOPPED ; 
 scalar_t__ FLAG_S ; 
 int /*<<< orphan*/  OPER_I_16 () ; 
 int /*<<< orphan*/  STOP_LEVEL_STOP ; 
 int /*<<< orphan*/  m68ki_exception_privilege_violation () ; 
 scalar_t__ m68ki_remaining_cycles ; 
 int /*<<< orphan*/  m68ki_set_sr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m68ki_trace_t0 () ; 

void m68k_op_stop(void)
{
	if(FLAG_S)
	{
		uint new_sr = OPER_I_16();
		m68ki_trace_t0();			   /* auto-disable (see m68kcpu.h) */
		CPU_STOPPED |= STOP_LEVEL_STOP;
		m68ki_set_sr(new_sr);
		m68ki_remaining_cycles = 0;
		return;
	}
	m68ki_exception_privilege_violation();
}