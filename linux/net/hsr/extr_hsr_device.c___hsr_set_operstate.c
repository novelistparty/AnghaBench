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
struct net_device {int operstate; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_base_lock ; 
 int /*<<< orphan*/  netdev_state_change (struct net_device*) ; 
 int /*<<< orphan*/  write_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  write_unlock_bh (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void __hsr_set_operstate(struct net_device *dev, int transition)
{
	write_lock_bh(&dev_base_lock);
	if (dev->operstate != transition) {
		dev->operstate = transition;
		write_unlock_bh(&dev_base_lock);
		netdev_state_change(dev);
	} else {
		write_unlock_bh(&dev_base_lock);
	}
}