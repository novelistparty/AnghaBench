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
typedef  int /*<<< orphan*/  vm_offset_t ;
struct pmap {int dummy; } ;
typedef  int register_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_MASK ; 
 int TLBHI_ASID_MASK ; 
 int TLBHI_ENTRY (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int intr_disable () ; 
 int /*<<< orphan*/  intr_restore (int) ; 
 int mips_rd_entryhi () ; 
 int mips_rd_index () ; 
 int /*<<< orphan*/  mips_wr_entryhi (int) ; 
 int /*<<< orphan*/  mips_wr_pagemask (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmap_asid (struct pmap*) ; 
 int /*<<< orphan*/  tlb_invalidate_one (int) ; 
 int /*<<< orphan*/  tlb_probe () ; 

void
tlb_invalidate_address(struct pmap *pmap, vm_offset_t va)
{
	register_t asid;
	register_t s;
	int i;

	va &= ~PAGE_MASK;

	s = intr_disable();
	asid = mips_rd_entryhi() & TLBHI_ASID_MASK;

	mips_wr_pagemask(0);
	mips_wr_entryhi(TLBHI_ENTRY(va, pmap_asid(pmap)));
	tlb_probe();
	i = mips_rd_index();
	if (i >= 0)
		tlb_invalidate_one(i);

	mips_wr_entryhi(asid);
	intr_restore(s);
}