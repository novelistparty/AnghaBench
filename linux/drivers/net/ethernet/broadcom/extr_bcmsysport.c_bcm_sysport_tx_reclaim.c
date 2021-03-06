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
struct netdev_queue {int dummy; } ;
struct bcm_sysport_tx_ring {int /*<<< orphan*/  lock; int /*<<< orphan*/  index; } ;
struct bcm_sysport_priv {int /*<<< orphan*/  netdev; } ;

/* Variables and functions */
 unsigned int __bcm_sysport_tx_reclaim (struct bcm_sysport_priv*,struct bcm_sysport_tx_ring*) ; 
 struct netdev_queue* netdev_get_tx_queue (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_tx_wake_queue (struct netdev_queue*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static unsigned int bcm_sysport_tx_reclaim(struct bcm_sysport_priv *priv,
					   struct bcm_sysport_tx_ring *ring)
{
	struct netdev_queue *txq;
	unsigned int released;
	unsigned long flags;

	txq = netdev_get_tx_queue(priv->netdev, ring->index);

	spin_lock_irqsave(&ring->lock, flags);
	released = __bcm_sysport_tx_reclaim(priv, ring);
	if (released)
		netif_tx_wake_queue(txq);

	spin_unlock_irqrestore(&ring->lock, flags);

	return released;
}