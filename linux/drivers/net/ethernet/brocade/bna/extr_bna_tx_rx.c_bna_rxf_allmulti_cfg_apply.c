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
struct bna_rxf {int /*<<< orphan*/  rxmode_active; int /*<<< orphan*/  rxmode_pending_bitmask; int /*<<< orphan*/  rxmode_pending; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNA_RXMODE_ALLMULTI ; 
 int /*<<< orphan*/  BNA_STATUS_T_DISABLED ; 
 int /*<<< orphan*/  BNA_STATUS_T_ENABLED ; 
 int /*<<< orphan*/  allmulti_inactive (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bna_bfi_mcast_filter_req (struct bna_rxf*,int /*<<< orphan*/ ) ; 
 scalar_t__ is_allmulti_disable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ is_allmulti_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
bna_rxf_allmulti_cfg_apply(struct bna_rxf *rxf)
{
	/* Enable/disable allmulti mode */
	if (is_allmulti_enable(rxf->rxmode_pending,
				rxf->rxmode_pending_bitmask)) {
		/* move allmulti configuration from pending -> active */
		allmulti_inactive(rxf->rxmode_pending,
				rxf->rxmode_pending_bitmask);
		rxf->rxmode_active |= BNA_RXMODE_ALLMULTI;
		bna_bfi_mcast_filter_req(rxf, BNA_STATUS_T_DISABLED);
		return 1;
	} else if (is_allmulti_disable(rxf->rxmode_pending,
					rxf->rxmode_pending_bitmask)) {
		/* move allmulti configuration from pending -> active */
		allmulti_inactive(rxf->rxmode_pending,
				rxf->rxmode_pending_bitmask);
		rxf->rxmode_active &= ~BNA_RXMODE_ALLMULTI;
		bna_bfi_mcast_filter_req(rxf, BNA_STATUS_T_ENABLED);
		return 1;
	}

	return 0;
}