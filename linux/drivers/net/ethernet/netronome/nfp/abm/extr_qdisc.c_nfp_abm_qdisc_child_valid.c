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
struct nfp_qdisc {scalar_t__* children; } ;

/* Variables and functions */
 scalar_t__ NFP_QDISC_UNTRACKED ; 

__attribute__((used)) static bool nfp_abm_qdisc_child_valid(struct nfp_qdisc *qdisc, unsigned int id)
{
	return qdisc->children[id] &&
	       qdisc->children[id] != NFP_QDISC_UNTRACKED;
}