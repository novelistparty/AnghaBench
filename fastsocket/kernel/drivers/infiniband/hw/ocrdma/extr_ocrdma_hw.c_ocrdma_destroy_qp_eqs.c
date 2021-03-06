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
struct ocrdma_dev {int eq_cnt; int /*<<< orphan*/ * qp_eq_tbl; } ;

/* Variables and functions */
 int /*<<< orphan*/  ocrdma_destroy_eq (struct ocrdma_dev*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ocrdma_destroy_qp_eqs(struct ocrdma_dev *dev)
{
	int i;

	/* deallocate the data path eqs */
	for (i = 0; i < dev->eq_cnt; i++)
		ocrdma_destroy_eq(dev, &dev->qp_eq_tbl[i]);
}