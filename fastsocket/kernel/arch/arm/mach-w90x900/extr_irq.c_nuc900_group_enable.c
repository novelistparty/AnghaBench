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
struct group_irq {unsigned int gpen; } ;

/* Variables and functions */
 int /*<<< orphan*/  REG_AIC_GEN ; 
 unsigned long __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void nuc900_group_enable(struct group_irq *gpirq, int enable)
{
	unsigned int groupen = gpirq->gpen;
	unsigned long regval;

	regval = __raw_readl(REG_AIC_GEN);

	if (enable)
		regval |= groupen;
	else
		regval &= ~groupen;

	__raw_writel(regval, REG_AIC_GEN);
}