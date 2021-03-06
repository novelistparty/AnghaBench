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
struct cpufreq_policy {int /*<<< orphan*/  cpu; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpufreq_frequency_table_put_attr (int /*<<< orphan*/ ) ; 
 unsigned int max_multiplier ; 
 int /*<<< orphan*/  powernow_k6_set_state (unsigned int) ; 

__attribute__((used)) static int powernow_k6_cpu_exit(struct cpufreq_policy *policy)
{
	unsigned int i;
	for (i = 0; i < 8; i++) {
		if (i == max_multiplier)
			powernow_k6_set_state(i);
	}
	cpufreq_frequency_table_put_attr(policy->cpu);
	return 0;
}