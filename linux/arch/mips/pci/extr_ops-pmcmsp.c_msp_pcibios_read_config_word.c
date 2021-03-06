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
typedef  int u32 ;
struct pci_bus {int dummy; } ;

/* Variables and functions */
 int PCIBIOS_BAD_REGISTER_NUMBER ; 
 int PCIBIOS_SUCCESSFUL ; 
 int /*<<< orphan*/  PCI_ACCESS_READ ; 
 scalar_t__ msp_pcibios_config_access (int /*<<< orphan*/ ,struct pci_bus*,unsigned int,int,int*) ; 

__attribute__((used)) static int
msp_pcibios_read_config_word(struct pci_bus *bus,
				unsigned int devfn,
				int where,
				u32 *val)
{
	u32 data = 0;

	/* if (where & 1) */	/* Commented out non-compliant code.
				 * Should allow word access to configuration
				 * registers, with only exception being when
				 * the word access would wrap around into
				 * the next dword.
				 */
	if ((where & 3) == 3) {
		*val = 0xFFFFFFFF;
		return PCIBIOS_BAD_REGISTER_NUMBER;
	}

	/*
	 * If the config access did not complete normally (e.g., underwent
	 * master abort) do the PCI compliant thing, which is to supply an
	 * all ones value.
	 */
	if (msp_pcibios_config_access(PCI_ACCESS_READ, bus, devfn,
					where, &data)) {
		*val = 0xFFFFFFFF;
		return -1;
	}

	*val = (data >> ((where & 3) << 3)) & 0x0ffff;

	return PCIBIOS_SUCCESSFUL;
}