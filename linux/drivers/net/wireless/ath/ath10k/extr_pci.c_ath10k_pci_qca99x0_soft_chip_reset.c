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
struct ath10k {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ath10k_pci_irq_disable (struct ath10k*) ; 
 int ath10k_pci_qca99x0_chip_reset (struct ath10k*) ; 

__attribute__((used)) static int ath10k_pci_qca99x0_soft_chip_reset(struct ath10k *ar)
{
	ath10k_pci_irq_disable(ar);
	return ath10k_pci_qca99x0_chip_reset(ar);
}