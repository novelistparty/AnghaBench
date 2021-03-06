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
struct xp_ops2 {int /*<<< orphan*/  xp_control; } ;
struct xp_ops {int /*<<< orphan*/  xp_destroy; int /*<<< orphan*/  xp_freeargs; int /*<<< orphan*/  xp_reply; int /*<<< orphan*/  xp_getargs; int /*<<< orphan*/  xp_stat; int /*<<< orphan*/ * xp_recv; } ;
struct TYPE_3__ {struct xp_ops2* xp_ops2; struct xp_ops* xp_ops; } ;
typedef  TYPE_1__ SVCXPRT ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ops_lock ; 
 int /*<<< orphan*/  svc_dg_control ; 
 int /*<<< orphan*/  svc_dg_destroy ; 
 int /*<<< orphan*/  svc_dg_freeargs ; 
 int /*<<< orphan*/  svc_dg_getargs ; 
 int /*<<< orphan*/ * svc_dg_recv ; 
 int /*<<< orphan*/  svc_dg_reply ; 
 int /*<<< orphan*/  svc_dg_stat ; 

__attribute__((used)) static void
svc_dg_ops(SVCXPRT *xprt)
{
	static struct xp_ops ops;
	static struct xp_ops2 ops2;

/* VARIABLES PROTECTED BY ops_lock: ops */

	mutex_lock(&ops_lock);
	if (ops.xp_recv == NULL) {
		ops.xp_recv = svc_dg_recv;
		ops.xp_stat = svc_dg_stat;
		ops.xp_getargs = svc_dg_getargs;
		ops.xp_reply = svc_dg_reply;
		ops.xp_freeargs = svc_dg_freeargs;
		ops.xp_destroy = svc_dg_destroy;
		ops2.xp_control = svc_dg_control;
	}
	xprt->xp_ops = &ops;
	xprt->xp_ops2 = &ops2;
	mutex_unlock(&ops_lock);
}