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
typedef  scalar_t__ vm_offset_t ;

/* Variables and functions */
 scalar_t__ PAGE_SIZE ; 
 int /*<<< orphan*/  pmap_kremove (scalar_t__) ; 
 int /*<<< orphan*/  tlb_flush_range (scalar_t__,scalar_t__) ; 

void
pmap_qremove(vm_offset_t sva, int count)
{
	vm_offset_t va;

	va = sva;
	while (count-- > 0) {
		pmap_kremove(va);
		va += PAGE_SIZE;
	}
	tlb_flush_range(sva, va - sva);
}