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
struct mt76_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MT_WPDMA_GLO_CFG ; 
 int MT_WPDMA_GLO_CFG_RX_DMA_BUSY ; 
 int MT_WPDMA_GLO_CFG_TX_DMA_BUSY ; 
 int __mt76_poll (struct mt76_dev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline bool
mt76x02_wait_for_wpdma(struct mt76_dev *dev, int timeout)
{
	return __mt76_poll(dev, MT_WPDMA_GLO_CFG,
			   MT_WPDMA_GLO_CFG_TX_DMA_BUSY |
			   MT_WPDMA_GLO_CFG_RX_DMA_BUSY,
			   0, timeout);
}