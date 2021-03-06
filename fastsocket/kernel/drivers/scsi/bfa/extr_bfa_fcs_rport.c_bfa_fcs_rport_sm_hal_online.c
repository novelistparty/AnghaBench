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
struct bfa_fcs_rport_s {int pwwn; int pid; int /*<<< orphan*/  fcs; int /*<<< orphan*/  plogi_pending; } ;
typedef  enum rport_event { ____Placeholder_rport_event } rport_event ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_TRUE ; 
#define  RPSM_EVENT_ADDRESS_CHANGE 137 
#define  RPSM_EVENT_DELETE 136 
#define  RPSM_EVENT_FAB_SCN 135 
#define  RPSM_EVENT_HCB_ONLINE 134 
#define  RPSM_EVENT_LOGO_IMP 133 
#define  RPSM_EVENT_LOGO_RCVD 132 
#define  RPSM_EVENT_PLOGI_COMP 131 
#define  RPSM_EVENT_PLOGI_RCVD 130 
#define  RPSM_EVENT_PRLO_RCVD 129 
#define  RPSM_EVENT_SCN_OFFLINE 128 
 int /*<<< orphan*/  bfa_fcs_rport_fcs_offline_action (struct bfa_fcs_rport_s*) ; 
 int /*<<< orphan*/  bfa_fcs_rport_hal_online_action (struct bfa_fcs_rport_s*) ; 
 int /*<<< orphan*/  bfa_fcs_rport_sm_fc4_logorcv ; 
 int /*<<< orphan*/  bfa_fcs_rport_sm_fc4_logosend ; 
 int /*<<< orphan*/  bfa_fcs_rport_sm_fc4_offline ; 
 int /*<<< orphan*/  bfa_fcs_rport_sm_online ; 
 int /*<<< orphan*/  bfa_sm_fault (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bfa_sm_set_state (struct bfa_fcs_rport_s*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_trc (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void
bfa_fcs_rport_sm_hal_online(struct bfa_fcs_rport_s *rport,
			enum rport_event event)
{
	bfa_trc(rport->fcs, rport->pwwn);
	bfa_trc(rport->fcs, rport->pid);
	bfa_trc(rport->fcs, event);

	switch (event) {
	case RPSM_EVENT_HCB_ONLINE:
		bfa_sm_set_state(rport, bfa_fcs_rport_sm_online);
		bfa_fcs_rport_hal_online_action(rport);
		break;

	case RPSM_EVENT_PLOGI_COMP:
		break;

	case RPSM_EVENT_PRLO_RCVD:
	case RPSM_EVENT_LOGO_RCVD:
		bfa_sm_set_state(rport, bfa_fcs_rport_sm_fc4_logorcv);
		bfa_fcs_rport_fcs_offline_action(rport);
		break;

	case RPSM_EVENT_FAB_SCN:
	case RPSM_EVENT_LOGO_IMP:
	case RPSM_EVENT_ADDRESS_CHANGE:
	case RPSM_EVENT_SCN_OFFLINE:
		bfa_sm_set_state(rport, bfa_fcs_rport_sm_fc4_offline);
		bfa_fcs_rport_fcs_offline_action(rport);
		break;

	case RPSM_EVENT_PLOGI_RCVD:
		rport->plogi_pending = BFA_TRUE;
		bfa_sm_set_state(rport, bfa_fcs_rport_sm_fc4_offline);
		bfa_fcs_rport_fcs_offline_action(rport);
		break;

	case RPSM_EVENT_DELETE:
		bfa_sm_set_state(rport, bfa_fcs_rport_sm_fc4_logosend);
		bfa_fcs_rport_fcs_offline_action(rport);
		break;

	default:
		bfa_sm_fault(rport->fcs, event);
	}
}