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
struct v10_compute_mqd {int dummy; } ;
struct amdgpu_ring {int /*<<< orphan*/  queue; int /*<<< orphan*/  pipe; int /*<<< orphan*/  me; scalar_t__ wptr; struct v10_compute_mqd* mqd_ptr; struct amdgpu_device* adev; } ;
struct TYPE_3__ {struct v10_compute_mqd** mqd_backup; } ;
struct TYPE_4__ {TYPE_1__ mec; } ;
struct amdgpu_device {TYPE_2__ gfx; int /*<<< orphan*/  srbm_mutex; scalar_t__ in_gpu_reset; } ;

/* Variables and functions */
 int AMDGPU_MAX_COMPUTE_RINGS ; 
 int /*<<< orphan*/  amdgpu_ring_clear_ring (struct amdgpu_ring*) ; 
 int /*<<< orphan*/  gfx_v10_0_compute_mqd_init (struct amdgpu_ring*) ; 
 int /*<<< orphan*/  gfx_v10_0_kiq_init_register (struct amdgpu_ring*) ; 
 int /*<<< orphan*/  gfx_v10_0_kiq_setting (struct amdgpu_ring*) ; 
 int /*<<< orphan*/  memcpy (struct v10_compute_mqd*,struct v10_compute_mqd*,int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nv_grbm_select (struct amdgpu_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int gfx_v10_0_kiq_init_queue(struct amdgpu_ring *ring)
{
	struct amdgpu_device *adev = ring->adev;
	struct v10_compute_mqd *mqd = ring->mqd_ptr;
	int mqd_idx = AMDGPU_MAX_COMPUTE_RINGS;

	gfx_v10_0_kiq_setting(ring);

	if (adev->in_gpu_reset) { /* for GPU_RESET case */
		/* reset MQD to a clean status */
		if (adev->gfx.mec.mqd_backup[mqd_idx])
			memcpy(mqd, adev->gfx.mec.mqd_backup[mqd_idx], sizeof(*mqd));

		/* reset ring buffer */
		ring->wptr = 0;
		amdgpu_ring_clear_ring(ring);

		mutex_lock(&adev->srbm_mutex);
		nv_grbm_select(adev, ring->me, ring->pipe, ring->queue, 0);
		gfx_v10_0_kiq_init_register(ring);
		nv_grbm_select(adev, 0, 0, 0, 0);
		mutex_unlock(&adev->srbm_mutex);
	} else {
		memset((void *)mqd, 0, sizeof(*mqd));
		mutex_lock(&adev->srbm_mutex);
		nv_grbm_select(adev, ring->me, ring->pipe, ring->queue, 0);
		gfx_v10_0_compute_mqd_init(ring);
		gfx_v10_0_kiq_init_register(ring);
		nv_grbm_select(adev, 0, 0, 0, 0);
		mutex_unlock(&adev->srbm_mutex);

		if (adev->gfx.mec.mqd_backup[mqd_idx])
			memcpy(adev->gfx.mec.mqd_backup[mqd_idx], mqd, sizeof(*mqd));
	}

	return 0;
}