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
 int /*<<< orphan*/  ia64_cpu_local_tick () ; 
 int /*<<< orphan*/  touch_softlockup_watchdog () ; 

__attribute__((used)) static void xen_local_tick_resume(void)
{
	/* Just trigger a tick.  */
	ia64_cpu_local_tick();
	touch_softlockup_watchdog();
}