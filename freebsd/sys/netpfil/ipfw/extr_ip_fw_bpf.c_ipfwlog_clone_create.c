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
struct ifnet {int if_flags; int if_mtu; int /*<<< orphan*/  if_hdrlen; int /*<<< orphan*/  if_output; int /*<<< orphan*/  if_ioctl; } ;
struct if_clone {int dummy; } ;
typedef  int /*<<< orphan*/  caddr_t ;

/* Variables and functions */
 int /*<<< orphan*/  DLT_PFLOG ; 
 int EEXIST ; 
 int ENOSPC ; 
 int IFF_MULTICAST ; 
 int IFF_SIMPLEX ; 
 int IFF_UP ; 
 int /*<<< orphan*/  IFT_PFLOG ; 
 int /*<<< orphan*/  PFLOG_HDRLEN ; 
 struct ifnet* V_pflog_if ; 
 int /*<<< orphan*/  bpfattach (struct ifnet*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bpfdetach (struct ifnet*) ; 
 struct ifnet* if_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  if_attach (struct ifnet*) ; 
 int /*<<< orphan*/  if_detach (struct ifnet*) ; 
 int /*<<< orphan*/  if_free (struct ifnet*) ; 
 int /*<<< orphan*/  if_initname (struct ifnet*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ipfw_bpf_ioctl ; 
 int /*<<< orphan*/  ipfw_bpf_output ; 
 int /*<<< orphan*/  ipfwlogname ; 

__attribute__((used)) static int
ipfwlog_clone_create(struct if_clone *ifc, int unit, caddr_t params)
{
	struct ifnet *ifp;

	ifp = if_alloc(IFT_PFLOG);
	if (ifp == NULL)
		return (ENOSPC);
	if_initname(ifp, ipfwlogname, unit);
	ifp->if_flags = IFF_UP | IFF_SIMPLEX | IFF_MULTICAST;
	ifp->if_mtu = 65536;
	ifp->if_ioctl = ipfw_bpf_ioctl;
	ifp->if_output = ipfw_bpf_output;
	ifp->if_hdrlen = PFLOG_HDRLEN;
	if_attach(ifp);
	bpfattach(ifp, DLT_PFLOG, PFLOG_HDRLEN);
	if (V_pflog_if != NULL) {
		bpfdetach(ifp);
		if_detach(ifp);
		if_free(ifp);
		return (EEXIST);
	}
	V_pflog_if = ifp;
	return (0);
}