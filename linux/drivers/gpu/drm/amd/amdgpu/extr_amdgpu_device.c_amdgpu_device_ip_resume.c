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
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int amdgpu_device_fw_loading (struct amdgpu_device*) ; 
 int amdgpu_device_ip_resume_phase1 (struct amdgpu_device*) ; 
 int amdgpu_device_ip_resume_phase2 (struct amdgpu_device*) ; 

__attribute__((used)) static int amdgpu_device_ip_resume(struct amdgpu_device *adev)
{
	int r;

	r = amdgpu_device_ip_resume_phase1(adev);
	if (r)
		return r;

	r = amdgpu_device_fw_loading(adev);
	if (r)
		return r;

	r = amdgpu_device_ip_resume_phase2(adev);

	return r;
}