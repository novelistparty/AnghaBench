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
typedef  int /*<<< orphan*/  pa_source_info_cb_t ;
typedef  int /*<<< orphan*/  pa_operation ;
typedef  int int_fast32_t ;

/* Variables and functions */
 scalar_t__ PA_OPERATION_RUNNING ; 
 int /*<<< orphan*/ * pa_context_get_source_info_by_name (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,void*) ; 
 scalar_t__ pa_operation_get_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pa_operation_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pulseaudio_context ; 
 scalar_t__ pulseaudio_context_ready () ; 
 int /*<<< orphan*/  pulseaudio_lock () ; 
 int /*<<< orphan*/  pulseaudio_unlock () ; 
 int /*<<< orphan*/  pulseaudio_wait () ; 

int_fast32_t pulseaudio_get_source_info(pa_source_info_cb_t cb,
					const char *name, void *userdata)
{
	if (pulseaudio_context_ready() < 0)
		return -1;

	pulseaudio_lock();

	pa_operation *op = pa_context_get_source_info_by_name(
		pulseaudio_context, name, cb, userdata);
	if (!op) {
		pulseaudio_unlock();
		return -1;
	}
	while (pa_operation_get_state(op) == PA_OPERATION_RUNNING)
		pulseaudio_wait();
	pa_operation_unref(op);

	pulseaudio_unlock();

	return 0;
}