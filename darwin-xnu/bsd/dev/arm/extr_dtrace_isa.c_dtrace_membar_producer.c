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

inline void
dtrace_membar_producer(void)
{
#if __ARM_SMP__
	__asm__ volatile("dmb ish" : : : "memory");
#else
	__asm__ volatile("nop" : : : "memory");
#endif
}