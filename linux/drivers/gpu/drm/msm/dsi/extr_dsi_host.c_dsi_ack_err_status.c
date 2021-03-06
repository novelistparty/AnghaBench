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
typedef  scalar_t__ u32 ;
struct msm_dsi_host {int /*<<< orphan*/  err_work_state; } ;

/* Variables and functions */
 int /*<<< orphan*/  DSI_ERR_STATE_ACK ; 
 int /*<<< orphan*/  REG_DSI_ACK_ERR_STATUS ; 
 scalar_t__ dsi_read (struct msm_dsi_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dsi_write (struct msm_dsi_host*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void dsi_ack_err_status(struct msm_dsi_host *msm_host)
{
	u32 status;

	status = dsi_read(msm_host, REG_DSI_ACK_ERR_STATUS);

	if (status) {
		dsi_write(msm_host, REG_DSI_ACK_ERR_STATUS, status);
		/* Writing of an extra 0 needed to clear error bits */
		dsi_write(msm_host, REG_DSI_ACK_ERR_STATUS, 0);
		msm_host->err_work_state |= DSI_ERR_STATE_ACK;
	}
}