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
 int GPIO_HIGH ; 
 int GPIO_LOW ; 
 int* IOP3XX_GPOD ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 

void gpio_line_set(int line, int value)
{
	unsigned long flags;

	local_irq_save(flags);
	if (value == GPIO_LOW) {
		*IOP3XX_GPOD &= ~(1 << line);
	} else if (value == GPIO_HIGH) {
		*IOP3XX_GPOD |= 1 << line;
	}
	local_irq_restore(flags);
}