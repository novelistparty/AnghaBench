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
struct request {scalar_t__ part; } ;
struct mq_inflight {scalar_t__ part; int /*<<< orphan*/ * inflight; } ;
struct blk_mq_hw_ctx {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static bool blk_mq_check_inflight(struct blk_mq_hw_ctx *hctx,
				  struct request *rq, void *priv,
				  bool reserved)
{
	struct mq_inflight *mi = priv;

	/*
	 * index[0] counts the specific partition that was asked for.
	 */
	if (rq->part == mi->part)
		mi->inflight[0]++;

	return true;
}