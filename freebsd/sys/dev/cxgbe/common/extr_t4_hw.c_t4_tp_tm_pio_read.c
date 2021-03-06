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
typedef  int /*<<< orphan*/  u32 ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  A_TP_TM_PIO_ADDR ; 
 int /*<<< orphan*/  A_TP_TM_PIO_DATA ; 
 int /*<<< orphan*/  t4_tp_indirect_rw (struct adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 

void t4_tp_tm_pio_read(struct adapter *adap, u32 *buff, u32 nregs,
		       u32 start_index, bool sleep_ok)
{
	t4_tp_indirect_rw(adap, A_TP_TM_PIO_ADDR, A_TP_TM_PIO_DATA, buff,
			  nregs, start_index, 1, sleep_ok);
}