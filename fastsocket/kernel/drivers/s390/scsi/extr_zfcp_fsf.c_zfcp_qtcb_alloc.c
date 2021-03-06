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
struct fsf_qtcb {int dummy; } ;
typedef  int /*<<< orphan*/  mempool_t ;
struct TYPE_2__ {int /*<<< orphan*/  qtcb_cache; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 struct fsf_qtcb* kmem_cache_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int /*<<< orphan*/ *) ; 
 struct fsf_qtcb* mempool_alloc (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct fsf_qtcb*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ unlikely (int) ; 
 TYPE_1__ zfcp_data ; 

__attribute__((used)) static struct fsf_qtcb *zfcp_qtcb_alloc(mempool_t *pool)
{
	struct fsf_qtcb *qtcb;

	if (likely(pool))
		qtcb = mempool_alloc(pool, GFP_ATOMIC);
	else
		qtcb = kmem_cache_alloc(zfcp_data.qtcb_cache, GFP_ATOMIC);

	if (unlikely(!qtcb))
		return NULL;

	memset(qtcb, 0, sizeof(*qtcb));
	return qtcb;
}