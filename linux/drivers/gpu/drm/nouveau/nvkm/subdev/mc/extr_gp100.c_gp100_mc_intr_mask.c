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
typedef  int u32 ;
struct nvkm_mc {int dummy; } ;
struct gp100_mc {int mask; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 struct gp100_mc* gp100_mc (struct nvkm_mc*) ; 
 int /*<<< orphan*/  gp100_mc_intr_update (struct gp100_mc*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

void
gp100_mc_intr_mask(struct nvkm_mc *base, u32 mask, u32 intr)
{
	struct gp100_mc *mc = gp100_mc(base);
	unsigned long flags;
	spin_lock_irqsave(&mc->lock, flags);
	mc->mask = (mc->mask & ~mask) | intr;
	gp100_mc_intr_update(mc);
	spin_unlock_irqrestore(&mc->lock, flags);
}