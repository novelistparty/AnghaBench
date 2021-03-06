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
struct rk_timer {int dummy; } ;
struct clock_event_device {int dummy; } ;

/* Variables and functions */
 struct rk_timer* rk_timer (struct clock_event_device*) ; 
 int /*<<< orphan*/  rk_timer_disable (struct rk_timer*) ; 

__attribute__((used)) static int rk_timer_shutdown(struct clock_event_device *ce)
{
	struct rk_timer *timer = rk_timer(ce);

	rk_timer_disable(timer);
	return 0;
}