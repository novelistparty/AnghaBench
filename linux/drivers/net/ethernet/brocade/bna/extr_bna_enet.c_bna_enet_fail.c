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
struct bna_enet {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNA_ENET_F_IOCETH_READY ; 
 int /*<<< orphan*/  ENET_E_FAIL ; 
 int /*<<< orphan*/  bfa_fsm_send_event (struct bna_enet*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bna_enet_fail(struct bna_enet *enet)
{
	enet->flags &= ~BNA_ENET_F_IOCETH_READY;
	bfa_fsm_send_event(enet, ENET_E_FAIL);
}