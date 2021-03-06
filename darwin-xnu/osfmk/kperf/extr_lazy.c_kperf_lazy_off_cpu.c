#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* thread_t ;
struct TYPE_4__ {int reason; } ;

/* Variables and functions */
 int AST_SCHEDULING ; 
 int /*<<< orphan*/  kperf_lazy_cpu_sample (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
kperf_lazy_off_cpu(thread_t thread)
{
	/* try to lazily sample the CPU if the thread was pre-empted */
	if ((thread->reason & AST_SCHEDULING) != 0) {
		kperf_lazy_cpu_sample(thread, 0, 0);
    }
}