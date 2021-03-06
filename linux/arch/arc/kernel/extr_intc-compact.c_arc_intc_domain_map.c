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
struct irq_domain {int dummy; } ;
typedef  int irq_hw_number_t ;

/* Variables and functions */
#define  TIMER0_IRQ 128 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  handle_percpu_irq ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_percpu_devid (unsigned int) ; 
 int /*<<< orphan*/  onchip_intc ; 

__attribute__((used)) static int arc_intc_domain_map(struct irq_domain *d, unsigned int irq,
			       irq_hw_number_t hw)
{
	switch (hw) {
	case TIMER0_IRQ:
		irq_set_percpu_devid(irq);
		irq_set_chip_and_handler(irq, &onchip_intc, handle_percpu_irq);
		break;
	default:
		irq_set_chip_and_handler(irq, &onchip_intc, handle_level_irq);
	}
	return 0;
}