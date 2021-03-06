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
struct bnad {int dummy; } ;
struct bna_cq_entry {scalar_t__ valid; } ;
struct bna_ccb {int q_depth; scalar_t__ sw_q; } ;

/* Variables and functions */

__attribute__((used)) static void
bnad_cq_cleanup(struct bnad *bnad, struct bna_ccb *ccb)
{
	struct bna_cq_entry *cmpl;
	int i;

	for (i = 0; i < ccb->q_depth; i++) {
		cmpl = &((struct bna_cq_entry *)ccb->sw_q)[i];
		cmpl->valid = 0;
	}
}