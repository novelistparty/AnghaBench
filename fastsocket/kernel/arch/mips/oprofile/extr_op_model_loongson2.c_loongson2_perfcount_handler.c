#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
struct pt_regs {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {int cnt1_enabled; int cnt2_enabled; int reset_counter1; int reset_counter2; } ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int LOONGSON2_PERFCNT_OVERFLOW ; 
 struct pt_regs* get_irq_regs () ; 
 int /*<<< orphan*/  oprofile_add_sample (struct pt_regs*,int) ; 
 int read_c0_perfcnt () ; 
 TYPE_1__ reg ; 
 int /*<<< orphan*/  sample_lock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  write_c0_perfcnt (int) ; 

__attribute__((used)) static irqreturn_t loongson2_perfcount_handler(int irq, void *dev_id)
{
	uint64_t counter, counter1, counter2;
	struct pt_regs *regs = get_irq_regs();
	int enabled;
	unsigned long flags;

	/*
	 * LOONGSON2 defines two 32-bit performance counters.
	 * To avoid a race updating the registers we need to stop the counters
	 * while we're messing with
	 * them ...
	 */

	/* Check whether the irq belongs to me */
	enabled = reg.cnt1_enabled | reg.cnt2_enabled;
	if (!enabled)
		return IRQ_NONE;

	counter = read_c0_perfcnt();
	counter1 = counter & 0xffffffff;
	counter2 = counter >> 32;

	spin_lock_irqsave(&sample_lock, flags);

	if (counter1 & LOONGSON2_PERFCNT_OVERFLOW) {
		if (reg.cnt1_enabled)
			oprofile_add_sample(regs, 0);
		counter1 = reg.reset_counter1;
	}
	if (counter2 & LOONGSON2_PERFCNT_OVERFLOW) {
		if (reg.cnt2_enabled)
			oprofile_add_sample(regs, 1);
		counter2 = reg.reset_counter2;
	}

	spin_unlock_irqrestore(&sample_lock, flags);

	write_c0_perfcnt((counter2 << 32) | counter1);

	return IRQ_HANDLED;
}