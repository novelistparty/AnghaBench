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
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sched_register_mutex ; 
 scalar_t__ tracer_enabled ; 
 int /*<<< orphan*/  tracing_stop_sched_switch () ; 

void tracing_stop_sched_switch_record(void)
{
	mutex_lock(&sched_register_mutex);
	tracer_enabled--;
	WARN_ON(tracer_enabled < 0);
	mutex_unlock(&sched_register_mutex);

	tracing_stop_sched_switch();
}