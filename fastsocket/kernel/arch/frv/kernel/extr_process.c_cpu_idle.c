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

/* Variables and functions */
 int /*<<< orphan*/  check_pgt_cache () ; 
 int /*<<< orphan*/  frv_dma_inprogress ; 
 int /*<<< orphan*/  idle () ; 
 int /*<<< orphan*/  need_resched () ; 
 int /*<<< orphan*/  preempt_disable () ; 
 int /*<<< orphan*/  preempt_enable_no_resched () ; 
 int /*<<< orphan*/  schedule () ; 

void cpu_idle(void)
{
	/* endless idle loop with no priority at all */
	while (1) {
		while (!need_resched()) {
			check_pgt_cache();

			if (!frv_dma_inprogress && idle)
				idle();
		}

		preempt_enable_no_resched();
		schedule();
		preempt_disable();
	}
}