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
struct ape_dev {int /*<<< orphan*/  irq_count; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 

__attribute__((used)) static irqreturn_t altpciechdma_isr(int irq, void *dev_id)
{
	struct ape_dev *ape = (struct ape_dev *)dev_id;
	if (!ape)
		return IRQ_NONE;
	ape->irq_count++;
	return IRQ_HANDLED;
}