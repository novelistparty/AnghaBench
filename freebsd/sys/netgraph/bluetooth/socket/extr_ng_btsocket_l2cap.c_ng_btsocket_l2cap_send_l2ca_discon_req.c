#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_int32_t ;
struct TYPE_6__ {int /*<<< orphan*/  token; } ;
struct ng_mesg {scalar_t__ data; TYPE_1__ header; } ;
struct TYPE_8__ {int /*<<< orphan*/  idtype; int /*<<< orphan*/  lcid; } ;
typedef  TYPE_3__ ng_l2cap_l2ca_discon_ip ;
typedef  TYPE_4__* ng_btsocket_l2cap_pcb_p ;
struct TYPE_9__ {TYPE_2__* rt; int /*<<< orphan*/  idtype; int /*<<< orphan*/  cid; int /*<<< orphan*/  pcb_mtx; } ;
struct TYPE_7__ {int /*<<< orphan*/ * hook; } ;

/* Variables and functions */
 int ENETDOWN ; 
 int ENOMEM ; 
 int /*<<< orphan*/  MA_OWNED ; 
 int /*<<< orphan*/  M_NOWAIT ; 
 int /*<<< orphan*/  NGM_L2CAP_COOKIE ; 
 int /*<<< orphan*/  NGM_L2CAP_L2CA_DISCON ; 
 scalar_t__ NG_HOOK_NOT_VALID (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  NG_MKMESSAGE (struct ng_mesg*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NG_SEND_MSG_HOOK (int,int /*<<< orphan*/ ,struct ng_mesg*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtx_assert (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ng_btsocket_l2cap_node ; 

__attribute__((used)) static int
ng_btsocket_l2cap_send_l2ca_discon_req(u_int32_t token,
		ng_btsocket_l2cap_pcb_p pcb)
{
	struct ng_mesg		*msg = NULL;
	ng_l2cap_l2ca_discon_ip	*ip = NULL;
	int			 error = 0;

	mtx_assert(&pcb->pcb_mtx, MA_OWNED);

	if (pcb->rt == NULL || 
	    pcb->rt->hook == NULL || NG_HOOK_NOT_VALID(pcb->rt->hook))
		return (ENETDOWN); 

	NG_MKMESSAGE(msg, NGM_L2CAP_COOKIE, NGM_L2CAP_L2CA_DISCON,
		sizeof(*ip), M_NOWAIT);
	if (msg == NULL)
		return (ENOMEM);

	msg->header.token = token;

	ip = (ng_l2cap_l2ca_discon_ip *)(msg->data);
	ip->lcid = pcb->cid;
	ip->idtype = pcb->idtype;

	NG_SEND_MSG_HOOK(error, ng_btsocket_l2cap_node, msg,pcb->rt->hook, 0);

	return (error);
}