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
struct pt_regs {unsigned long pc; unsigned long sr; unsigned long sp; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPR_SR ; 
 unsigned long SPR_SR_SM ; 
 int /*<<< orphan*/  memset (struct pt_regs*,int /*<<< orphan*/ ,int) ; 
 unsigned long mfspr (int /*<<< orphan*/ ) ; 

void start_thread(struct pt_regs *regs, unsigned long pc, unsigned long sp)
{
	unsigned long sr = mfspr(SPR_SR) & ~SPR_SR_SM;

	memset(regs, 0, sizeof(struct pt_regs));

	regs->pc = pc;
	regs->sr = sr;
	regs->sp = sp;
}