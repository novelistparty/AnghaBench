#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int /*<<< orphan*/  inp6_hops; scalar_t__ inp6_ifindex; int /*<<< orphan*/  inp6_cksum; scalar_t__ inp6_hlim; } ;
struct TYPE_13__ {int /*<<< orphan*/  inp4_ip_tos; } ;
struct TYPE_11__ {int /*<<< orphan*/  inp6_local; } ;
struct TYPE_9__ {int /*<<< orphan*/  inp6_foreign; } ;
struct inpcb_compat {TYPE_7__ inp_depend6; TYPE_5__ inp_depend4; TYPE_3__ inp_dependladdr; TYPE_1__ inp_dependfaddr; int /*<<< orphan*/  inp_ip_p; int /*<<< orphan*/  inp_ip_ttl; int /*<<< orphan*/  inp_vflag; int /*<<< orphan*/  inp_flow; int /*<<< orphan*/  inp_flags; int /*<<< orphan*/  inp_gencnt; scalar_t__ nat_cookie; scalar_t__ nat_owner; int /*<<< orphan*/  inp_lport; int /*<<< orphan*/  inp_fport; } ;
struct TYPE_16__ {int /*<<< orphan*/  inp6_hops; int /*<<< orphan*/  inp6_cksum; } ;
struct TYPE_14__ {int /*<<< orphan*/  inp4_ip_tos; } ;
struct TYPE_12__ {int /*<<< orphan*/  inp6_local; } ;
struct TYPE_10__ {int /*<<< orphan*/  inp6_foreign; } ;
struct inpcb {TYPE_8__ inp_depend6; TYPE_6__ inp_depend4; TYPE_4__ inp_dependladdr; TYPE_2__ inp_dependfaddr; int /*<<< orphan*/  inp_ip_p; int /*<<< orphan*/  inp_ip_ttl; int /*<<< orphan*/  inp_vflag; int /*<<< orphan*/  inp_flow; int /*<<< orphan*/  inp_flags; int /*<<< orphan*/  inp_gencnt; int /*<<< orphan*/  inp_lport; int /*<<< orphan*/  inp_fport; } ;

/* Variables and functions */
 int /*<<< orphan*/  bzero (struct inpcb_compat*,int) ; 

void
inpcb_to_compat(struct inpcb *inp, struct inpcb_compat *inp_compat)
{
	bzero(inp_compat, sizeof (*inp_compat));
	inp_compat->inp_fport = inp->inp_fport;
	inp_compat->inp_lport = inp->inp_lport;
	inp_compat->nat_owner = 0;
	inp_compat->nat_cookie = 0;
	inp_compat->inp_gencnt = inp->inp_gencnt;
	inp_compat->inp_flags = inp->inp_flags;
	inp_compat->inp_flow = inp->inp_flow;
	inp_compat->inp_vflag = inp->inp_vflag;
	inp_compat->inp_ip_ttl = inp->inp_ip_ttl;
	inp_compat->inp_ip_p = inp->inp_ip_p;
	inp_compat->inp_dependfaddr.inp6_foreign =
	    inp->inp_dependfaddr.inp6_foreign;
	inp_compat->inp_dependladdr.inp6_local =
	    inp->inp_dependladdr.inp6_local;
	inp_compat->inp_depend4.inp4_ip_tos = inp->inp_depend4.inp4_ip_tos;
	inp_compat->inp_depend6.inp6_hlim = 0;
	inp_compat->inp_depend6.inp6_cksum = inp->inp_depend6.inp6_cksum;
	inp_compat->inp_depend6.inp6_ifindex = 0;
	inp_compat->inp_depend6.inp6_hops = inp->inp_depend6.inp6_hops;
}