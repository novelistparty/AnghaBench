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
struct sk_buff {int dummy; } ;
struct net_device {int dummy; } ;

/* Variables and functions */
 int NETDEV_TX_OK ; 
 int /*<<< orphan*/  dev_kfree_skb (struct sk_buff*) ; 

__attribute__((used)) static int dvb_net_tx(struct sk_buff *skb, struct net_device *dev)
{
	dev_kfree_skb(skb);
	return NETDEV_TX_OK;
}