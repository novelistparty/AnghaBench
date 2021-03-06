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
typedef  int uint64_t ;

/* Variables and functions */
 int PCIM_BAR_MEM_PREFETCH ; 
 scalar_t__ PCI_BAR_IO (int) ; 

__attribute__((used)) static const char *
pci_maptype(uint64_t mapreg)
{

	if (PCI_BAR_IO(mapreg))
		return ("I/O Port");
	if (mapreg & PCIM_BAR_MEM_PREFETCH)
		return ("Prefetchable Memory");
	return ("Memory");
}