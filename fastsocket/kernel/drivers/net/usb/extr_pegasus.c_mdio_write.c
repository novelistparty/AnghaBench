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
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  pegasus_t ;

/* Variables and functions */
 scalar_t__ netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  write_mii_word (int /*<<< orphan*/ *,int,int,int) ; 

__attribute__((used)) static void mdio_write(struct net_device *dev, int phy_id, int loc, int val)
{
	pegasus_t *pegasus = (pegasus_t *) netdev_priv(dev);

	write_mii_word(pegasus, phy_id, loc, val);
}