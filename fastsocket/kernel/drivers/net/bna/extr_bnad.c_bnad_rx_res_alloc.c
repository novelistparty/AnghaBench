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
typedef  int /*<<< orphan*/  uint ;
struct bnad {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  intr_info; int /*<<< orphan*/  mem_info; } ;
struct bna_res_info {scalar_t__ res_type; TYPE_1__ res_u; } ;

/* Variables and functions */
 int /*<<< orphan*/  BNAD_INTR_RX ; 
 scalar_t__ BNA_RES_T_INTR ; 
 scalar_t__ BNA_RES_T_MEM ; 
 int BNA_RX_RES_T_MAX ; 
 int bnad_mem_alloc (struct bnad*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bnad_rx_res_free (struct bnad*,struct bna_res_info*) ; 
 int bnad_txrx_irq_alloc (struct bnad*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
bnad_rx_res_alloc(struct bnad *bnad, struct bna_res_info *res_info,
		  uint rx_id)
{
	int i, err = 0;

	/* All memory needs to be allocated before setup_ccbs */
	for (i = 0; i < BNA_RX_RES_T_MAX; i++) {
		if (res_info[i].res_type == BNA_RES_T_MEM)
			err = bnad_mem_alloc(bnad,
					&res_info[i].res_u.mem_info);
		else if (res_info[i].res_type == BNA_RES_T_INTR)
			err = bnad_txrx_irq_alloc(bnad, BNAD_INTR_RX, rx_id,
					&res_info[i].res_u.intr_info);
		if (err)
			goto err_return;
	}
	return 0;

err_return:
	bnad_rx_res_free(bnad, res_info);
	return err;
}