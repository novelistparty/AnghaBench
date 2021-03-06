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
typedef  unsigned int u64 ;
typedef  unsigned int u32 ;
struct nixge_priv {size_t tx_bd_ci; int /*<<< orphan*/  dma_err_tasklet; int /*<<< orphan*/ * tx_bd_v; int /*<<< orphan*/  ndev; } ;
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  scalar_t__ dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned int XAXIDMA_IRQ_ALL_MASK ; 
 unsigned int XAXIDMA_IRQ_DELAY_MASK ; 
 unsigned int XAXIDMA_IRQ_ERROR_MASK ; 
 unsigned int XAXIDMA_IRQ_IOC_MASK ; 
 int /*<<< orphan*/  XAXIDMA_RX_CR_OFFSET ; 
 int /*<<< orphan*/  XAXIDMA_TX_CR_OFFSET ; 
 int /*<<< orphan*/  XAXIDMA_TX_SR_OFFSET ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*,...) ; 
 struct nixge_priv* netdev_priv (void*) ; 
 unsigned int nixge_dma_read_reg (struct nixge_priv*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nixge_dma_write_reg (struct nixge_priv*,int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ nixge_hw_dma_bd_get_addr (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  nixge_start_xmit_done (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 

__attribute__((used)) static irqreturn_t nixge_tx_irq(int irq, void *_ndev)
{
	struct nixge_priv *priv = netdev_priv(_ndev);
	struct net_device *ndev = _ndev;
	unsigned int status;
	dma_addr_t phys;
	u32 cr;

	status = nixge_dma_read_reg(priv, XAXIDMA_TX_SR_OFFSET);
	if (status & (XAXIDMA_IRQ_IOC_MASK | XAXIDMA_IRQ_DELAY_MASK)) {
		nixge_dma_write_reg(priv, XAXIDMA_TX_SR_OFFSET, status);
		nixge_start_xmit_done(priv->ndev);
		goto out;
	}
	if (!(status & XAXIDMA_IRQ_ALL_MASK)) {
		netdev_err(ndev, "No interrupts asserted in Tx path\n");
		return IRQ_NONE;
	}
	if (status & XAXIDMA_IRQ_ERROR_MASK) {
		phys = nixge_hw_dma_bd_get_addr(&priv->tx_bd_v[priv->tx_bd_ci],
						phys);

		netdev_err(ndev, "DMA Tx error 0x%x\n", status);
		netdev_err(ndev, "Current BD is at: 0x%llx\n", (u64)phys);

		cr = nixge_dma_read_reg(priv, XAXIDMA_TX_CR_OFFSET);
		/* Disable coalesce, delay timer and error interrupts */
		cr &= (~XAXIDMA_IRQ_ALL_MASK);
		/* Write to the Tx channel control register */
		nixge_dma_write_reg(priv, XAXIDMA_TX_CR_OFFSET, cr);

		cr = nixge_dma_read_reg(priv, XAXIDMA_RX_CR_OFFSET);
		/* Disable coalesce, delay timer and error interrupts */
		cr &= (~XAXIDMA_IRQ_ALL_MASK);
		/* Write to the Rx channel control register */
		nixge_dma_write_reg(priv, XAXIDMA_RX_CR_OFFSET, cr);

		tasklet_schedule(&priv->dma_err_tasklet);
		nixge_dma_write_reg(priv, XAXIDMA_TX_SR_OFFSET, status);
	}
out:
	return IRQ_HANDLED;
}