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
struct ixgbevf_adapter {int num_rx_queues; int /*<<< orphan*/  hw; int /*<<< orphan*/ * rx_ring; } ;

/* Variables and functions */
 int /*<<< orphan*/  hw_dbg (int /*<<< orphan*/ *,char*,int) ; 
 int ixgbevf_setup_rx_resources (struct ixgbevf_adapter*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ixgbevf_setup_all_rx_resources(struct ixgbevf_adapter *adapter)
{
	int i, err = 0;

	for (i = 0; i < adapter->num_rx_queues; i++) {
		err = ixgbevf_setup_rx_resources(adapter, &adapter->rx_ring[i]);
		if (!err)
			continue;
		hw_dbg(&adapter->hw,
		       "Allocation for Rx Queue %u failed\n", i);
		break;
	}
	return err;
}