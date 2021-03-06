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
struct bna_ioceth {int /*<<< orphan*/ * bna; int /*<<< orphan*/  ioc; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_nw_ioc_detach (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
bna_ioceth_uninit(struct bna_ioceth *ioceth)
{
	bfa_nw_ioc_detach(&ioceth->ioc);

	ioceth->bna = NULL;
}