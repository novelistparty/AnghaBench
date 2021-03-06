#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct ecore_hwfn {TYPE_1__* p_rdma_info; } ;
struct TYPE_2__ {int /*<<< orphan*/  lock; int /*<<< orphan*/  tcp_cid_map; int /*<<< orphan*/  proto; } ;

/* Variables and functions */
 int /*<<< orphan*/  OSAL_SPIN_LOCK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OSAL_SPIN_UNLOCK (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ecore_bmap_set_id (struct ecore_hwfn*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ ecore_cxt_get_proto_cid_start (struct ecore_hwfn*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
ecore_iwarp_set_tcp_cid(struct ecore_hwfn *p_hwfn, u32 cid)
{
	cid -= ecore_cxt_get_proto_cid_start(p_hwfn,
					     p_hwfn->p_rdma_info->proto);

	OSAL_SPIN_LOCK(&p_hwfn->p_rdma_info->lock);
	ecore_bmap_set_id(p_hwfn,
			  &p_hwfn->p_rdma_info->tcp_cid_map,
			  cid);
	OSAL_SPIN_UNLOCK(&p_hwfn->p_rdma_info->lock);
}