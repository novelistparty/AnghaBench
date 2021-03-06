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
struct TYPE_2__ {int /*<<< orphan*/  cgs_device; int /*<<< orphan*/  parent; } ;
struct amdgpu_device {TYPE_1__ acp; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  amdgpu_cgs_create_device (struct amdgpu_device*) ; 

__attribute__((used)) static int acp_sw_init(void *handle)
{
	struct amdgpu_device *adev = (struct amdgpu_device *)handle;

	adev->acp.parent = adev->dev;

	adev->acp.cgs_device =
		amdgpu_cgs_create_device(adev);
	if (!adev->acp.cgs_device)
		return -EINVAL;

	return 0;
}