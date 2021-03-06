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
struct TYPE_2__ {int /*<<< orphan*/  cpmnmimr; int /*<<< orphan*/  cpmmcmr; int /*<<< orphan*/  cpmcimr; int /*<<< orphan*/  cpmimr; } ;

/* Variables and functions */
 int get_hard_smp_processor_id (int) ; 
 TYPE_1__* rcpm_v1_regs ; 
 int /*<<< orphan*/  setbits32 (int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static void rcpm_v1_irq_mask(int cpu)
{
	int hw_cpu = get_hard_smp_processor_id(cpu);
	unsigned int mask = 1 << hw_cpu;

	setbits32(&rcpm_v1_regs->cpmimr, mask);
	setbits32(&rcpm_v1_regs->cpmcimr, mask);
	setbits32(&rcpm_v1_regs->cpmmcmr, mask);
	setbits32(&rcpm_v1_regs->cpmnmimr, mask);
}