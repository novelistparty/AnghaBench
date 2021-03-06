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
struct bfa_fcs_lport_s {int dummy; } ;
struct bfa_fcs_lport_ns_s {struct bfa_fcs_lport_s* port; } ;

/* Variables and functions */
 struct bfa_fcs_lport_ns_s* BFA_FCS_GET_NS_FROM_PORT (struct bfa_fcs_lport_s*) ; 
 int /*<<< orphan*/  bfa_fcs_lport_ns_sm_offline ; 
 int /*<<< orphan*/  bfa_sm_set_state (struct bfa_fcs_lport_ns_s*,int /*<<< orphan*/ ) ; 

void
bfa_fcs_lport_ns_init(struct bfa_fcs_lport_s *port)
{
	struct bfa_fcs_lport_ns_s *ns = BFA_FCS_GET_NS_FROM_PORT(port);

	ns->port = port;
	bfa_sm_set_state(ns, bfa_fcs_lport_ns_sm_offline);
}