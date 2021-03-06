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
struct TYPE_3__ {int /*<<< orphan*/  object; } ;
typedef  TYPE_1__ tqueue_st ;

/* Variables and functions */
 int /*<<< orphan*/  __lwp_objmgr_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __lwp_objmgr_free (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  _lwp_tqueue_objects ; 

__attribute__((used)) static __inline__ void __lwp_tqueue_free(tqueue_st *tq)
{
	__lwp_objmgr_close(&_lwp_tqueue_objects,&tq->object);
	__lwp_objmgr_free(&_lwp_tqueue_objects,&tq->object);
}