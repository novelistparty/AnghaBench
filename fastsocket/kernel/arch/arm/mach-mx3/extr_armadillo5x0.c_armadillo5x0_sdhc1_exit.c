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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IOMUX_TO_GPIO (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IOMUX_TO_IRQ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MX31_PIN_ATA_DMACK ; 
 int /*<<< orphan*/  MX31_PIN_ATA_RESET_B ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void armadillo5x0_sdhc1_exit(struct device *dev, void *data)
{
	free_irq(IOMUX_TO_IRQ(MX31_PIN_ATA_DMACK), data);
	gpio_free(IOMUX_TO_GPIO(MX31_PIN_ATA_DMACK));
	gpio_free(IOMUX_TO_GPIO(MX31_PIN_ATA_RESET_B));
}