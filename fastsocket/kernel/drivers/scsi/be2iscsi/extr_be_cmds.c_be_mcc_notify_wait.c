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
struct beiscsi_hba {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  be_mcc_notify (struct beiscsi_hba*) ; 
 int be_mcc_wait_compl (struct beiscsi_hba*) ; 

int be_mcc_notify_wait(struct beiscsi_hba *phba)
{
	be_mcc_notify(phba);
	return be_mcc_wait_compl(phba);
}