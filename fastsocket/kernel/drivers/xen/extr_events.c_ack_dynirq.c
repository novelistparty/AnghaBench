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
 scalar_t__ VALID_EVTCHN (int) ; 
 int /*<<< orphan*/  clear_evtchn (int) ; 
 int evtchn_from_irq (unsigned int) ; 
 int /*<<< orphan*/  move_native_irq (unsigned int) ; 

__attribute__((used)) static void ack_dynirq(unsigned int irq)
{
	int evtchn = evtchn_from_irq(irq);

	move_native_irq(irq);

	if (VALID_EVTCHN(evtchn))
		clear_evtchn(evtchn);
}