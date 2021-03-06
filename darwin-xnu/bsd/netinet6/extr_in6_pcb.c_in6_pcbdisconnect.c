#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct socket {int so_flags; int so_state; int /*<<< orphan*/  so_state_change_cnt; } ;
struct inpcb {TYPE_1__* inp_pcbinfo; int /*<<< orphan*/  inp_flow; scalar_t__ inp_fport; int /*<<< orphan*/  in6p_faddr; struct socket* inp_socket; } ;
typedef  int /*<<< orphan*/  caddr_t ;
struct TYPE_2__ {int /*<<< orphan*/  ipi_lock; } ;

/* Variables and functions */
 scalar_t__ IPPROTO_UDP ; 
 int /*<<< orphan*/  IPV6_FLOWLABEL_MASK ; 
 scalar_t__ SOCK_PROTO (struct socket*) ; 
 int SOF_MP_SUBFLOW ; 
 int SS_NOFDREF ; 
 int /*<<< orphan*/  bzero (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  in6_pcbdetach (struct inpcb*) ; 
 int /*<<< orphan*/  in_pcbrehash (struct inpcb*) ; 
 int /*<<< orphan*/  lck_rw_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_rw_lock_exclusive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_rw_try_lock_exclusive (int /*<<< orphan*/ ) ; 
 scalar_t__ nstat_collect ; 
 int /*<<< orphan*/  nstat_pcb_cache (struct inpcb*) ; 
 int /*<<< orphan*/  socket_lock (struct socket*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  socket_unlock (struct socket*,int /*<<< orphan*/ ) ; 

void
in6_pcbdisconnect(struct inpcb *inp)
{
	struct socket *so = inp->inp_socket;

#if CONTENT_FILTER
	if (so)
		so->so_state_change_cnt++;
#endif

	if (!lck_rw_try_lock_exclusive(inp->inp_pcbinfo->ipi_lock)) {
		/* lock inversion issue, mostly with udp multicast packets */
		socket_unlock(so, 0);
		lck_rw_lock_exclusive(inp->inp_pcbinfo->ipi_lock);
		socket_lock(so, 0);
	}
	if (nstat_collect && SOCK_PROTO(so) == IPPROTO_UDP)
		nstat_pcb_cache(inp);
	bzero((caddr_t)&inp->in6p_faddr, sizeof (inp->in6p_faddr));
	inp->inp_fport = 0;
	/* clear flowinfo - RFC 6437 */
	inp->inp_flow &= ~IPV6_FLOWLABEL_MASK;
	in_pcbrehash(inp);
	lck_rw_done(inp->inp_pcbinfo->ipi_lock);
	/*
	 * A multipath subflow socket would have its SS_NOFDREF set by default,
	 * so check for SOF_MP_SUBFLOW socket flag before detaching the PCB;
	 * when the socket is closed for real, SOF_MP_SUBFLOW would be cleared.
	 */
	if (!(so->so_flags & SOF_MP_SUBFLOW) && (so->so_state & SS_NOFDREF))
		in6_pcbdetach(inp);
}