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
struct wakeup_source {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __pm_relax (struct wakeup_source*) ; 
 int /*<<< orphan*/  wakeup_source_free (struct wakeup_source*) ; 
 int /*<<< orphan*/  wakeup_source_record (struct wakeup_source*) ; 

void wakeup_source_destroy(struct wakeup_source *ws)
{
	if (!ws)
		return;

	__pm_relax(ws);
	wakeup_source_record(ws);
	wakeup_source_free(ws);
}