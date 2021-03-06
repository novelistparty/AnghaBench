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
struct bfa_fcs_fabric_s {int /*<<< orphan*/  lps; } ;
struct bfa_fcs_s {struct bfa_fcs_fabric_s fabric; } ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_FCS_FABRIC_SM_DELETE ; 
 int /*<<< orphan*/  bfa_lps_delete (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_sm_send_event (struct bfa_fcs_fabric_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_trc (struct bfa_fcs_s*,int /*<<< orphan*/ ) ; 

void
bfa_fcs_fabric_modexit(struct bfa_fcs_s *fcs)
{
	struct bfa_fcs_fabric_s *fabric;

	bfa_trc(fcs, 0);

	/*
	 * Cleanup base fabric.
	 */
	fabric = &fcs->fabric;
	bfa_lps_delete(fabric->lps);
	bfa_sm_send_event(fabric, BFA_FCS_FABRIC_SM_DELETE);
}