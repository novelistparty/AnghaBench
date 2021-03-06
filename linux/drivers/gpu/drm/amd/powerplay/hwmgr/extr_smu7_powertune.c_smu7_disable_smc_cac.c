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
typedef  int /*<<< orphan*/  uint16_t ;
struct smu7_hwmgr {int cac_enabled; } ;
struct pp_hwmgr {scalar_t__ backend; } ;

/* Variables and functions */
 int /*<<< orphan*/  PHM_PlatformCaps_CAC ; 
 scalar_t__ PPSMC_MSG_DisableCac ; 
 int /*<<< orphan*/  PP_ASSERT_WITH_CODE (int,char*,int) ; 
 scalar_t__ PP_CAP (int /*<<< orphan*/ ) ; 
 int smum_send_msg_to_smc (struct pp_hwmgr*,int /*<<< orphan*/ ) ; 

int smu7_disable_smc_cac(struct pp_hwmgr *hwmgr)
{
	struct smu7_hwmgr *data = (struct smu7_hwmgr *)(hwmgr->backend);
	int result = 0;

	if (PP_CAP(PHM_PlatformCaps_CAC) && data->cac_enabled) {
		int smc_result = smum_send_msg_to_smc(hwmgr,
				(uint16_t)(PPSMC_MSG_DisableCac));
		PP_ASSERT_WITH_CODE((smc_result == 0),
				"Failed to disable CAC in SMC.", result = -1);

		data->cac_enabled = false;
	}
	return result;
}