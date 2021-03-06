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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  request ;
typedef  int /*<<< orphan*/  pqisrc_softstate_t ;
typedef  int /*<<< orphan*/  pqisrc_raid_req_t ;
typedef  int /*<<< orphan*/  bmic_ident_ctrl_t ;

/* Variables and functions */
 int /*<<< orphan*/  BMIC_IDENTIFY_CONTROLLER ; 
 int /*<<< orphan*/  DBG_FUNC (char*) ; 
 int PQI_STATUS_SUCCESS ; 
 scalar_t__ RAID_CTLR_LUNID ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int pqisrc_build_send_raid_request (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int pqisrc_identify_ctrl(pqisrc_softstate_t *softs,
	bmic_ident_ctrl_t *buff)
{
	int ret = PQI_STATUS_SUCCESS;
	pqisrc_raid_req_t request;

	DBG_FUNC("IN\n");

	memset(&request, 0, sizeof(request));	
	ret =  pqisrc_build_send_raid_request(softs, &request, buff, sizeof(*buff), 
				BMIC_IDENTIFY_CONTROLLER, 0, (uint8_t *)RAID_CTLR_LUNID, NULL);
	DBG_FUNC("OUT\n");

	return ret;
}