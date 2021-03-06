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
struct pmu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __l2x0_pmu_enable () ; 
 scalar_t__ l2x0_pmu_num_active_counters () ; 

__attribute__((used)) static void l2x0_pmu_enable(struct pmu *pmu)
{
	if (l2x0_pmu_num_active_counters() == 0)
		return;

	__l2x0_pmu_enable();
}