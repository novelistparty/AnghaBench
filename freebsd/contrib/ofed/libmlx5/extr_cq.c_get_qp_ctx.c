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
typedef  scalar_t__ uint32_t ;
struct mlx5_resource {scalar_t__ rsn; } ;
struct mlx5_context {int dummy; } ;

/* Variables and functions */
 int CQ_OK ; 
 int CQ_POLL_ERR ; 
 scalar_t__ mlx5_find_qp (struct mlx5_context*,scalar_t__) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline int get_qp_ctx(struct mlx5_context *mctx,
			     struct mlx5_resource **cur_rsc,
			     uint32_t qpn)
{
	if (!*cur_rsc || (qpn != (*cur_rsc)->rsn)) {
		/*
		 * We do not have to take the QP table lock here,
		 * because CQs will be locked while QPs are removed
		 * from the table.
		 */
		*cur_rsc = (struct mlx5_resource *)mlx5_find_qp(mctx, qpn);
		if (unlikely(!*cur_rsc))
			return CQ_POLL_ERR;
	}

	return CQ_OK;
}