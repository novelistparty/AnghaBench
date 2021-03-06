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
struct sk_buff {int dummy; } ;
struct iwl_txq {size_t write_ptr; size_t read_ptr; int /*<<< orphan*/  lock; int /*<<< orphan*/  overflow_q; TYPE_1__* entries; } ;
struct iwl_trans_pcie {int cmd_queue; int /*<<< orphan*/  reg_lock; struct iwl_txq** txq; } ;
struct iwl_trans {int /*<<< orphan*/  op_mode; } ;
struct TYPE_2__ {struct sk_buff* skb; } ;

/* Variables and functions */
 int /*<<< orphan*/  IWL_DEBUG_TX_REPLY (struct iwl_trans*,char*,int,size_t) ; 
 struct iwl_trans_pcie* IWL_TRANS_GET_PCIE_TRANS (struct iwl_trans*) ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 struct sk_buff* __skb_dequeue (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iwl_op_mode_free_skb (int /*<<< orphan*/ ,struct sk_buff*) ; 
 int /*<<< orphan*/  iwl_pcie_clear_cmd_in_flight (struct iwl_trans*) ; 
 int /*<<< orphan*/  iwl_pcie_free_tso_page (struct iwl_trans_pcie*,struct sk_buff*) ; 
 int /*<<< orphan*/  iwl_pcie_txq_free_tfd (struct iwl_trans*,struct iwl_txq*) ; 
 size_t iwl_queue_inc_wrap (struct iwl_trans*,size_t) ; 
 int /*<<< orphan*/  iwl_wake_queue (struct iwl_trans*,struct iwl_txq*) ; 
 int /*<<< orphan*/  skb_queue_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void iwl_pcie_txq_unmap(struct iwl_trans *trans, int txq_id)
{
	struct iwl_trans_pcie *trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans);
	struct iwl_txq *txq = trans_pcie->txq[txq_id];

	spin_lock_bh(&txq->lock);
	while (txq->write_ptr != txq->read_ptr) {
		IWL_DEBUG_TX_REPLY(trans, "Q %d Free %d\n",
				   txq_id, txq->read_ptr);

		if (txq_id != trans_pcie->cmd_queue) {
			struct sk_buff *skb = txq->entries[txq->read_ptr].skb;

			if (WARN_ON_ONCE(!skb))
				continue;

			iwl_pcie_free_tso_page(trans_pcie, skb);
		}
		iwl_pcie_txq_free_tfd(trans, txq);
		txq->read_ptr = iwl_queue_inc_wrap(trans, txq->read_ptr);

		if (txq->read_ptr == txq->write_ptr) {
			unsigned long flags;

			spin_lock_irqsave(&trans_pcie->reg_lock, flags);
			if (txq_id == trans_pcie->cmd_queue)
				iwl_pcie_clear_cmd_in_flight(trans);
			spin_unlock_irqrestore(&trans_pcie->reg_lock, flags);
		}
	}

	while (!skb_queue_empty(&txq->overflow_q)) {
		struct sk_buff *skb = __skb_dequeue(&txq->overflow_q);

		iwl_op_mode_free_skb(trans->op_mode, skb);
	}

	spin_unlock_bh(&txq->lock);

	/* just in case - this queue may have been stopped */
	iwl_wake_queue(trans, txq);
}