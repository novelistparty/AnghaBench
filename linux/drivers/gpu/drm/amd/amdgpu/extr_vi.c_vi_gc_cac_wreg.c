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
typedef  int /*<<< orphan*/  u32 ;
struct amdgpu_device {int /*<<< orphan*/  gc_cac_idx_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmGC_CAC_IND_DATA ; 
 int /*<<< orphan*/  mmGC_CAC_IND_INDEX ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void vi_gc_cac_wreg(struct amdgpu_device *adev, u32 reg, u32 v)
{
	unsigned long flags;

	spin_lock_irqsave(&adev->gc_cac_idx_lock, flags);
	WREG32(mmGC_CAC_IND_INDEX, (reg));
	WREG32(mmGC_CAC_IND_DATA, (v));
	spin_unlock_irqrestore(&adev->gc_cac_idx_lock, flags);
}