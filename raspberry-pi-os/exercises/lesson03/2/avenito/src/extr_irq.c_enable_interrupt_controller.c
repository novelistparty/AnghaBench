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
 int /*<<< orphan*/  ENABLE_IRQS_1 ; 
 int SYSTEM_TIMER_IRQ_1 ; 
 int en_AUX_INT ; 
 int /*<<< orphan*/  put32 (int /*<<< orphan*/ ,int) ; 

void enable_interrupt_controller()
{
	put32(ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1 | en_AUX_INT);
}