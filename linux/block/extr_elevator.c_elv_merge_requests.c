#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct request_queue {struct request* last_merge; struct elevator_queue* elevator; } ;
struct request {int dummy; } ;
struct elevator_queue {TYPE_2__* type; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* requests_merged ) (struct request_queue*,struct request*,struct request*) ;} ;
struct TYPE_4__ {TYPE_1__ ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  elv_rqhash_reposition (struct request_queue*,struct request*) ; 
 int /*<<< orphan*/  stub1 (struct request_queue*,struct request*,struct request*) ; 

void elv_merge_requests(struct request_queue *q, struct request *rq,
			     struct request *next)
{
	struct elevator_queue *e = q->elevator;

	if (e->type->ops.requests_merged)
		e->type->ops.requests_merged(q, rq, next);

	elv_rqhash_reposition(q, rq);
	q->last_merge = rq;
}