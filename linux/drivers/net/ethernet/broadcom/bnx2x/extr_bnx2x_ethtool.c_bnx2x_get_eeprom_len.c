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
struct net_device {int dummy; } ;
struct TYPE_2__ {int flash_size; } ;
struct bnx2x {TYPE_1__ common; } ;

/* Variables and functions */
 struct bnx2x* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int bnx2x_get_eeprom_len(struct net_device *dev)
{
	struct bnx2x *bp = netdev_priv(dev);

	return bp->common.flash_size;
}