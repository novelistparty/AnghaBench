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
struct task_struct {int dummy; } ;
struct msg_queue {int dummy; } ;
struct msg_msg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAY_READWRITE ; 
 int smk_curacc_msq (struct msg_queue*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int smack_msg_queue_msgrcv(struct msg_queue *msq, struct msg_msg *msg,
			struct task_struct *target, long type, int mode)
{
	return smk_curacc_msq(msq, MAY_READWRITE);
}