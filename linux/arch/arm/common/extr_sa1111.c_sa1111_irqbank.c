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
struct irq_data {int dummy; } ;

/* Variables and functions */
 int irqd_to_hwirq (struct irq_data*) ; 

__attribute__((used)) static int sa1111_irqbank(struct irq_data *d)
{
	return (irqd_to_hwirq(d) / 32) * 4;
}