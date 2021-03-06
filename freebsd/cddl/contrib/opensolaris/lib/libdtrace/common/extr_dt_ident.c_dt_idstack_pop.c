#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  dids_list; } ;
typedef  TYPE_1__ dt_idstack_t ;
typedef  int /*<<< orphan*/  dt_idhash_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  dt_list_delete (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * dt_list_prev (int /*<<< orphan*/ *) ; 

void
dt_idstack_pop(dt_idstack_t *sp, dt_idhash_t *dhp)
{
	assert(dt_list_prev(&sp->dids_list) == dhp);
	dt_list_delete(&sp->dids_list, dhp);
}