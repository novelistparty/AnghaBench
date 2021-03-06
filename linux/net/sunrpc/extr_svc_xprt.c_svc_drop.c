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
struct svc_rqst {int /*<<< orphan*/  rq_xprt; } ;

/* Variables and functions */
 int /*<<< orphan*/  dprintk (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svc_xprt_release (struct svc_rqst*) ; 
 int /*<<< orphan*/  trace_svc_drop (struct svc_rqst*) ; 

void svc_drop(struct svc_rqst *rqstp)
{
	trace_svc_drop(rqstp);
	dprintk("svc: xprt %p dropped request\n", rqstp->rq_xprt);
	svc_xprt_release(rqstp);
}