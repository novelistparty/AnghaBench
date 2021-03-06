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
typedef  union perf_event {int dummy; } perf_event ;
struct ordered_events {scalar_t__ copy_on_queue; } ;

/* Variables and functions */
 union perf_event* __dup_event (struct ordered_events*,union perf_event*) ; 

__attribute__((used)) static union perf_event *dup_event(struct ordered_events *oe,
				   union perf_event *event)
{
	return oe->copy_on_queue ? __dup_event(oe, event) : event;
}