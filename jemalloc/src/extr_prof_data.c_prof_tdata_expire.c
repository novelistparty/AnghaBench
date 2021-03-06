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
typedef  int /*<<< orphan*/  tsdn_t ;
struct TYPE_4__ {int expired; int /*<<< orphan*/  lock; scalar_t__ attached; } ;
typedef  TYPE_1__ prof_tdata_t ;

/* Variables and functions */
 int /*<<< orphan*/  malloc_mutex_lock (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  malloc_mutex_unlock (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int prof_tdata_should_destroy (int /*<<< orphan*/ *,TYPE_1__*,int) ; 

__attribute__((used)) static bool
prof_tdata_expire(tsdn_t *tsdn, prof_tdata_t *tdata) {
	bool destroy_tdata;

	malloc_mutex_lock(tsdn, tdata->lock);
	if (!tdata->expired) {
		tdata->expired = true;
		destroy_tdata = tdata->attached ? false :
		    prof_tdata_should_destroy(tsdn, tdata, false);
	} else {
		destroy_tdata = false;
	}
	malloc_mutex_unlock(tsdn, tdata->lock);

	return destroy_tdata;
}