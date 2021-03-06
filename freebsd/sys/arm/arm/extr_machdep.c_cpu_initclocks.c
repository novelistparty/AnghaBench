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
 scalar_t__ PCPU_GET (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_initclocks_ap () ; 
 int /*<<< orphan*/  cpu_initclocks_bsp () ; 
 int /*<<< orphan*/  cpuid ; 

void
cpu_initclocks(void)
{

#ifdef SMP
	if (PCPU_GET(cpuid) == 0)
		cpu_initclocks_bsp();
	else
		cpu_initclocks_ap();
#else
	cpu_initclocks_bsp();
#endif
}