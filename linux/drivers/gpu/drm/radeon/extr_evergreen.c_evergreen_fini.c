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
struct radeon_device {int flags; int /*<<< orphan*/ * bios; } ;

/* Variables and functions */
 int RADEON_IS_IGP ; 
 int /*<<< orphan*/  evergreen_pcie_gart_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r600_dma_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  r600_irq_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  r600_vram_scratch_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  r700_cp_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_agp_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_atombios_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_audio_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_bo_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_fence_driver_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_gem_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_ib_pool_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_irq_kms_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_pm_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_uvd_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  radeon_wb_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  sumo_rlc_fini (struct radeon_device*) ; 
 int /*<<< orphan*/  uvd_v1_0_fini (struct radeon_device*) ; 

void evergreen_fini(struct radeon_device *rdev)
{
	radeon_pm_fini(rdev);
	radeon_audio_fini(rdev);
	r700_cp_fini(rdev);
	r600_dma_fini(rdev);
	r600_irq_fini(rdev);
	if (rdev->flags & RADEON_IS_IGP)
		sumo_rlc_fini(rdev);
	radeon_wb_fini(rdev);
	radeon_ib_pool_fini(rdev);
	radeon_irq_kms_fini(rdev);
	uvd_v1_0_fini(rdev);
	radeon_uvd_fini(rdev);
	evergreen_pcie_gart_fini(rdev);
	r600_vram_scratch_fini(rdev);
	radeon_gem_fini(rdev);
	radeon_fence_driver_fini(rdev);
	radeon_agp_fini(rdev);
	radeon_bo_fini(rdev);
	radeon_atombios_fini(rdev);
	kfree(rdev->bios);
	rdev->bios = NULL;
}