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
struct nouveau_fence {int /*<<< orphan*/  base; } ;
struct TYPE_3__ {struct dma_resv* resv; } ;
struct TYPE_4__ {TYPE_1__ base; } ;
struct nouveau_bo {TYPE_2__ bo; } ;
struct dma_resv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dma_resv_add_excl_fence (struct dma_resv*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dma_resv_add_shared_fence (struct dma_resv*,int /*<<< orphan*/ *) ; 

void
nouveau_bo_fence(struct nouveau_bo *nvbo, struct nouveau_fence *fence, bool exclusive)
{
	struct dma_resv *resv = nvbo->bo.base.resv;

	if (exclusive)
		dma_resv_add_excl_fence(resv, &fence->base);
	else if (fence)
		dma_resv_add_shared_fence(resv, &fence->base);
}