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
struct irq_domain {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int mbi_allocate_pci_domain(struct irq_domain *nexus_domain,
				   struct irq_domain **pci_domain)
{
	*pci_domain = NULL;
	return 0;
}