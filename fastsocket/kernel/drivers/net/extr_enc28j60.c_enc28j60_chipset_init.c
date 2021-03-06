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
struct enc28j60_net {int dummy; } ;

/* Variables and functions */
 int enc28j60_hw_init (struct enc28j60_net*) ; 
 struct enc28j60_net* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int enc28j60_chipset_init(struct net_device *dev)
{
	struct enc28j60_net *priv = netdev_priv(dev);

	return enc28j60_hw_init(priv);
}