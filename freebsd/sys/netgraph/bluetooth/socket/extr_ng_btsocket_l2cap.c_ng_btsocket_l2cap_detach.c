#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct socket {int /*<<< orphan*/ * so_pcb; } ;
typedef  TYPE_1__* ng_btsocket_l2cap_pcb_p ;
struct TYPE_8__ {int flags; scalar_t__ state; int /*<<< orphan*/  pcb_mtx; } ;

/* Variables and functions */
 int /*<<< orphan*/  KASSERT (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  LIST_REMOVE (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  M_NETGRAPH_BTSOCKET_L2CAP ; 
 scalar_t__ NG_BTSOCKET_L2CAP_CLOSED ; 
 scalar_t__ NG_BTSOCKET_L2CAP_DISCONNECTING ; 
 int NG_BTSOCKET_L2CAP_TIMO ; 
 int /*<<< orphan*/  bzero (TYPE_1__*,int) ; 
 int /*<<< orphan*/  free (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  next ; 
 int /*<<< orphan*/ * ng_btsocket_l2cap_node ; 
 int /*<<< orphan*/  ng_btsocket_l2cap_send_l2ca_discon_req (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  ng_btsocket_l2cap_sockets_mtx ; 
 int /*<<< orphan*/  ng_btsocket_l2cap_untimeout (TYPE_1__*) ; 
 TYPE_1__* so2l2cap_pcb (struct socket*) ; 
 int /*<<< orphan*/  soisdisconnected (struct socket*) ; 

void
ng_btsocket_l2cap_detach(struct socket *so)
{
	ng_btsocket_l2cap_pcb_p	pcb = so2l2cap_pcb(so);

	KASSERT(pcb != NULL, ("ng_btsocket_l2cap_detach: pcb == NULL"));

	if (ng_btsocket_l2cap_node == NULL) 
		return;

	mtx_lock(&ng_btsocket_l2cap_sockets_mtx);
	mtx_lock(&pcb->pcb_mtx);

	/* XXX what to do with pending request? */
	if (pcb->flags & NG_BTSOCKET_L2CAP_TIMO)
		ng_btsocket_l2cap_untimeout(pcb);

	if (pcb->state != NG_BTSOCKET_L2CAP_CLOSED &&
	    pcb->state != NG_BTSOCKET_L2CAP_DISCONNECTING)
		/* Send disconnect request with "zero" token */
		ng_btsocket_l2cap_send_l2ca_discon_req(0, pcb);

	pcb->state = NG_BTSOCKET_L2CAP_CLOSED;

	LIST_REMOVE(pcb, next);

	mtx_unlock(&pcb->pcb_mtx);
	mtx_unlock(&ng_btsocket_l2cap_sockets_mtx);

	mtx_destroy(&pcb->pcb_mtx);
	bzero(pcb, sizeof(*pcb));
	free(pcb, M_NETGRAPH_BTSOCKET_L2CAP);

	soisdisconnected(so);
	so->so_pcb = NULL;
}