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
typedef  scalar_t__ u8 ;
struct bna_rxf {scalar_t__ vlan_filter_status; scalar_t__ vlan_pending_bitmask; } ;
struct bna_rx {struct bna_rxf rxf; } ;

/* Variables and functions */
 scalar_t__ BFI_VLAN_BMASK_ALL ; 
 scalar_t__ BNA_STATUS_T_DISABLED ; 
 scalar_t__ BNA_STATUS_T_ENABLED ; 
 int /*<<< orphan*/  RXF_E_CONFIG ; 
 int /*<<< orphan*/  bfa_fsm_send_event (struct bna_rxf*,int /*<<< orphan*/ ) ; 

void
bna_rx_vlanfilter_enable(struct bna_rx *rx)
{
	struct bna_rxf *rxf = &rx->rxf;

	if (rxf->vlan_filter_status == BNA_STATUS_T_DISABLED) {
		rxf->vlan_filter_status = BNA_STATUS_T_ENABLED;
		rxf->vlan_pending_bitmask = (u8)BFI_VLAN_BMASK_ALL;
		bfa_fsm_send_event(rxf, RXF_E_CONFIG);
	}
}