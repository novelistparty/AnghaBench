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
struct net_device {scalar_t__ tx_queue_len; } ;

/* Variables and functions */
 int /*<<< orphan*/  macvlan_common_setup (struct net_device*) ; 

__attribute__((used)) static void macvlan_setup(struct net_device *dev)
{
	macvlan_common_setup(dev);
	dev->tx_queue_len	= 0;
}