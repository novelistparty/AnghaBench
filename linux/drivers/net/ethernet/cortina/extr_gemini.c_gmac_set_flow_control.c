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
typedef  int /*<<< orphan*/  u32 ;
struct net_device {int dummy; } ;
struct gemini_ethernet_port {int /*<<< orphan*/  config_lock; scalar_t__ gmac_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONFIG0_FLOW_CTL ; 
 int /*<<< orphan*/  CONFIG0_FLOW_RX ; 
 int /*<<< orphan*/  CONFIG0_FLOW_TX ; 
 scalar_t__ GMAC_CONFIG0 ; 
 struct gemini_ethernet_port* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void gmac_set_flow_control(struct net_device *netdev, bool tx, bool rx)
{
	struct gemini_ethernet_port *port = netdev_priv(netdev);
	unsigned long flags;
	u32 val;

	spin_lock_irqsave(&port->config_lock, flags);

	val = readl(port->gmac_base + GMAC_CONFIG0);
	val &= ~CONFIG0_FLOW_CTL;
	if (tx)
		val |= CONFIG0_FLOW_TX;
	if (rx)
		val |= CONFIG0_FLOW_RX;
	writel(val, port->gmac_base + GMAC_CONFIG0);

	spin_unlock_irqrestore(&port->config_lock, flags);
}