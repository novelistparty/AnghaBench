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
struct pp_hwmgr {int fan_ctrl_is_in_default_mode; int fan_ctrl_default_mode; int tmin; struct amdgpu_device* adev; } ;
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CG_FDO_CTRL2 ; 
 int CG_FDO_CTRL2__TMIN__SHIFT ; 
 int /*<<< orphan*/  FDO_PWM_MODE ; 
 int /*<<< orphan*/  REG_SET_FIELD (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THM ; 
 int /*<<< orphan*/  TMIN ; 
 int /*<<< orphan*/  WREG32_SOC15 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmCG_FDO_CTRL2 ; 

int vega10_fan_ctrl_set_default_mode(struct pp_hwmgr *hwmgr)
{
	struct amdgpu_device *adev = hwmgr->adev;

	if (!hwmgr->fan_ctrl_is_in_default_mode) {
		WREG32_SOC15(THM, 0, mmCG_FDO_CTRL2,
			REG_SET_FIELD(RREG32_SOC15(THM, 0, mmCG_FDO_CTRL2),
				CG_FDO_CTRL2, FDO_PWM_MODE,
				hwmgr->fan_ctrl_default_mode));
		WREG32_SOC15(THM, 0, mmCG_FDO_CTRL2,
			REG_SET_FIELD(RREG32_SOC15(THM, 0, mmCG_FDO_CTRL2),
				CG_FDO_CTRL2, TMIN,
				hwmgr->tmin << CG_FDO_CTRL2__TMIN__SHIFT));
		hwmgr->fan_ctrl_is_in_default_mode = true;
	}

	return 0;
}