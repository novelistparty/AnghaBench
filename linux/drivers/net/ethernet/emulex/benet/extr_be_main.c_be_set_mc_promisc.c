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
struct be_adapter {int if_flags; } ;

/* Variables and functions */
 int BE_IF_FLAGS_MCAST_PROMISCUOUS ; 
 int /*<<< orphan*/  ON ; 
 int be_cmd_rx_filter (struct be_adapter*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void be_set_mc_promisc(struct be_adapter *adapter)
{
	int status;

	if (adapter->if_flags & BE_IF_FLAGS_MCAST_PROMISCUOUS)
		return;

	status = be_cmd_rx_filter(adapter, BE_IF_FLAGS_MCAST_PROMISCUOUS, ON);
	if (!status)
		adapter->if_flags |= BE_IF_FLAGS_MCAST_PROMISCUOUS;
}