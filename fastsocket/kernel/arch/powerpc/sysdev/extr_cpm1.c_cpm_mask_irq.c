#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  cpic_cimr; } ;
struct TYPE_3__ {scalar_t__ hwirq; } ;

/* Variables and functions */
 int /*<<< orphan*/  clrbits32 (int /*<<< orphan*/ *,int) ; 
 TYPE_2__* cpic_reg ; 
 TYPE_1__* irq_map ; 

__attribute__((used)) static void cpm_mask_irq(unsigned int irq)
{
	unsigned int cpm_vec = (unsigned int)irq_map[irq].hwirq;

	clrbits32(&cpic_reg->cpic_cimr, (1 << cpm_vec));
}