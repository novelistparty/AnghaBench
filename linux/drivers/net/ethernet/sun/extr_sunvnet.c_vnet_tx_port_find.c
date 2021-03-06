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
struct vnet_port {int dummy; } ;
struct vnet {int dummy; } ;
struct sk_buff {int dummy; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 struct vnet_port* __tx_port_find (struct vnet*,struct sk_buff*) ; 
 struct vnet* netdev_priv (struct net_device*) ; 

__attribute__((used)) static struct vnet_port *vnet_tx_port_find(struct sk_buff *skb,
					   struct net_device *dev)
{
	struct vnet *vp = netdev_priv(dev);

	return __tx_port_find(vp, skb);
}