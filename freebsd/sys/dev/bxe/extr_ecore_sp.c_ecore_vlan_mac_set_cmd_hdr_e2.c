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
struct eth_classify_cmd_header {int cmd_general_data; int /*<<< orphan*/  func_id; int /*<<< orphan*/  client_id; } ;
struct ecore_raw_obj {int /*<<< orphan*/  func_id; int /*<<< orphan*/  cl_id; } ;
struct ecore_vlan_mac_obj {struct ecore_raw_obj raw; } ;
struct bxe_softc {int dummy; } ;

/* Variables and functions */
 int ETH_CLASSIFY_CMD_HEADER_IS_ADD ; 
 int ETH_CLASSIFY_CMD_HEADER_OPCODE_SHIFT ; 
 int ecore_vlan_mac_get_rx_tx_flag (struct ecore_vlan_mac_obj*) ; 

__attribute__((used)) static inline void ecore_vlan_mac_set_cmd_hdr_e2(struct bxe_softc *sc,
	struct ecore_vlan_mac_obj *o, bool add, int opcode,
	struct eth_classify_cmd_header *hdr)
{
	struct ecore_raw_obj *raw = &o->raw;

	hdr->client_id = raw->cl_id;
	hdr->func_id = raw->func_id;

	/* Rx or/and Tx (internal switching) configuration ? */
	hdr->cmd_general_data |=
		ecore_vlan_mac_get_rx_tx_flag(o);

	if (add)
		hdr->cmd_general_data |= ETH_CLASSIFY_CMD_HEADER_IS_ADD;

	hdr->cmd_general_data |=
		(opcode << ETH_CLASSIFY_CMD_HEADER_OPCODE_SHIFT);
}