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
struct mmc_host {int dummy; } ;
struct jz4740_mmc_host {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  JZ_MMC_IRQ_SDIO ; 
 int /*<<< orphan*/  jz4740_mmc_set_irq_enabled (struct jz4740_mmc_host*,int /*<<< orphan*/ ,int) ; 
 struct jz4740_mmc_host* mmc_priv (struct mmc_host*) ; 

__attribute__((used)) static void jz4740_mmc_enable_sdio_irq(struct mmc_host *mmc, int enable)
{
	struct jz4740_mmc_host *host = mmc_priv(mmc);
	jz4740_mmc_set_irq_enabled(host, JZ_MMC_IRQ_SDIO, enable);
}