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
struct TYPE_2__ {int /*<<< orphan*/  restart_queue; } ;
struct iavf_ring {TYPE_1__ tx_stats; int /*<<< orphan*/  queue_index; int /*<<< orphan*/  netdev; } ;

/* Variables and functions */
 int EBUSY ; 
 int IAVF_DESC_UNUSED (struct iavf_ring*) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  netif_start_subqueue (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netif_stop_subqueue (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_mb () ; 

int __iavf_maybe_stop_tx(struct iavf_ring *tx_ring, int size)
{
	netif_stop_subqueue(tx_ring->netdev, tx_ring->queue_index);
	/* Memory barrier before checking head and tail */
	smp_mb();

	/* Check again in a case another CPU has just made room available. */
	if (likely(IAVF_DESC_UNUSED(tx_ring) < size))
		return -EBUSY;

	/* A reprieve! - use start_queue because it doesn't call schedule */
	netif_start_subqueue(tx_ring->netdev, tx_ring->queue_index);
	++tx_ring->tx_stats.restart_queue;
	return 0;
}