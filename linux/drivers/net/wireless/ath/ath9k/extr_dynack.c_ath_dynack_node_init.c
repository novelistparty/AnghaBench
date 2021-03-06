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
struct ath_node {int /*<<< orphan*/  list; int /*<<< orphan*/  ackto; } ;
struct ath_dynack {int /*<<< orphan*/  qlock; int /*<<< orphan*/  nodes; int /*<<< orphan*/  ackto; } ;
struct ath_hw {struct ath_dynack dynack; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 

void ath_dynack_node_init(struct ath_hw *ah, struct ath_node *an)
{
	struct ath_dynack *da = &ah->dynack;

	an->ackto = da->ackto;

	spin_lock_bh(&da->qlock);
	list_add_tail(&an->list, &da->nodes);
	spin_unlock_bh(&da->qlock);
}