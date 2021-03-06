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
struct locomo {scalar_t__ irq; int /*<<< orphan*/  base; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ NO_IRQ ; 
 int /*<<< orphan*/  device_for_each_child (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct locomo*) ; 
 int /*<<< orphan*/  locomo_remove_child ; 
 int /*<<< orphan*/  set_irq_chained_handler (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_irq_data (scalar_t__,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void __locomo_remove(struct locomo *lchip)
{
	device_for_each_child(lchip->dev, NULL, locomo_remove_child);

	if (lchip->irq != NO_IRQ) {
		set_irq_chained_handler(lchip->irq, NULL);
		set_irq_data(lchip->irq, NULL);
	}

	iounmap(lchip->base);
	kfree(lchip);
}