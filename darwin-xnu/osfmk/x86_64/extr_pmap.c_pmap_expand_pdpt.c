#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vm_page_t ;
typedef  int vm_object_offset_t ;
typedef  scalar_t__ vm_map_offset_t ;
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  ppnum_t ;
typedef  TYPE_1__* pmap_t ;
typedef  int /*<<< orphan*/  pmap_paddr_t ;
typedef  int /*<<< orphan*/  pdpt_entry_t ;
typedef  scalar_t__ kern_return_t ;
typedef  scalar_t__ boolean_t ;
struct TYPE_14__ {int /*<<< orphan*/  pm_obj_pdpt; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG (char*,TYPE_1__*,void*) ; 
 int INTEL_EPT_EX ; 
 int INTEL_PTE_USER ; 
 scalar_t__ KERN_RESOURCE_SHORTAGE ; 
 scalar_t__ KERN_SUCCESS ; 
 int /*<<< orphan*/  OSAddAtomic (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  OSAddAtomic64 (int,int /*<<< orphan*/ *) ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/ * PDPT_ENTRY_NULL ; 
 scalar_t__ PD_ENTRY_NULL ; 
 unsigned int PMAP_EXPAND_OPTIONS_NOWAIT ; 
 int /*<<< orphan*/  PMAP_LOCK (TYPE_1__*) ; 
 int /*<<< orphan*/  PMAP_UNLOCK (TYPE_1__*) ; 
 int /*<<< orphan*/  PMAP_ZINFO_PALLOC (TYPE_1__*,int) ; 
 int /*<<< orphan*/  PMAP_ZINFO_PFREE (TYPE_1__*,int) ; 
 int PTE_READ (scalar_t__) ; 
 int PTE_WRITE (scalar_t__) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  VM_KERN_MEMORY_PTE ; 
 int /*<<< orphan*/  VM_PAGE_FREE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VM_PAGE_GET_PHYS_PAGE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VM_PAGE_NULL ; 
 int /*<<< orphan*/  VM_PAGE_WAIT () ; 
 int /*<<< orphan*/  alloc_ptepages_count ; 
 int /*<<< orphan*/  i386_ptob (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  inuse_ptepages_count ; 
 scalar_t__ is_ept_pmap (TYPE_1__*) ; 
 int pa_to_pte (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*,TYPE_1__*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 scalar_t__ pdptidx (TYPE_1__*,scalar_t__) ; 
 scalar_t__ pmap64_pde (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/ * pmap64_pdpt (TYPE_1__*,scalar_t__) ; 
 scalar_t__ pmap_expand_pml4 (TYPE_1__*,scalar_t__,unsigned int) ; 
 int /*<<< orphan*/  pmap_store_pte (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pmap_zero_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vm_object_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vm_object_unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vm_page_grab () ; 
 int /*<<< orphan*/  vm_page_insert_wired (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vm_page_lockspin_queues () ; 
 scalar_t__ vm_page_lookup (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  vm_page_unlock_queues () ; 
 int /*<<< orphan*/  vm_page_wire (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

kern_return_t
pmap_expand_pdpt(pmap_t map, vm_map_offset_t vaddr, unsigned int options)
{
	vm_page_t	m;
	pmap_paddr_t	pa;
	uint64_t	i;
	ppnum_t		pn;
	pdpt_entry_t	*pdptp;
	boolean_t	is_ept = is_ept_pmap(map);

	DBG("pmap_expand_pdpt(%p,%p)\n", map, (void *)vaddr);

	while ((pdptp = pmap64_pdpt(map, vaddr)) == PDPT_ENTRY_NULL) {
		kern_return_t pep4kr = pmap_expand_pml4(map, vaddr, options);
		if (pep4kr != KERN_SUCCESS)
			return pep4kr;
	}

	/*
	 *	Allocate a VM page for the pdpt page
	 */
	while ((m = vm_page_grab()) == VM_PAGE_NULL) {
		if (options & PMAP_EXPAND_OPTIONS_NOWAIT)
			return KERN_RESOURCE_SHORTAGE;
		VM_PAGE_WAIT();
	}

	/*
	 *	put the page into the pmap's obj list so it
	 *	can be found later.
	 */
	pn = VM_PAGE_GET_PHYS_PAGE(m);
	pa = i386_ptob(pn);
	i = pdptidx(map, vaddr);

	/*
	 *	Zero the page.
	 */
	pmap_zero_page(pn);

	vm_page_lockspin_queues();
	vm_page_wire(m, VM_KERN_MEMORY_PTE, TRUE);
	vm_page_unlock_queues();

	OSAddAtomic(1,  &inuse_ptepages_count);
	OSAddAtomic64(1,  &alloc_ptepages_count);
	PMAP_ZINFO_PALLOC(map, PAGE_SIZE);

	/* Take the oject lock (mutex) before the PMAP_LOCK (spinlock) */
	vm_object_lock(map->pm_obj_pdpt);

	PMAP_LOCK(map);
	/*
	 *	See if someone else expanded us first
	 */
	if (pmap64_pde(map, vaddr) != PD_ENTRY_NULL) {
		PMAP_UNLOCK(map);
		vm_object_unlock(map->pm_obj_pdpt);

		VM_PAGE_FREE(m);

		OSAddAtomic(-1,  &inuse_ptepages_count);
		PMAP_ZINFO_PFREE(map, PAGE_SIZE);
		return KERN_SUCCESS;
	}

#if 0 /* DEBUG */
       if (0 != vm_page_lookup(map->pm_obj_pdpt, (vm_object_offset_t)i * PAGE_SIZE)) {
	       panic("pmap_expand_pdpt: obj not empty, pmap %p pm_obj %p vaddr 0x%llx i 0x%llx\n",
		     map, map->pm_obj_pdpt, vaddr, i);
       }
#endif
	vm_page_insert_wired(m, map->pm_obj_pdpt, (vm_object_offset_t)i * PAGE_SIZE, VM_KERN_MEMORY_PTE);
	vm_object_unlock(map->pm_obj_pdpt);

	/*
	 *	Set the page directory entry for this page table.
	 */
	pdptp = pmap64_pdpt(map, vaddr); /* refetch under lock */

	pmap_store_pte(pdptp, pa_to_pte(pa)
				| PTE_READ(is_ept)
				| (is_ept ? INTEL_EPT_EX : INTEL_PTE_USER)
				| PTE_WRITE(is_ept));

	PMAP_UNLOCK(map);

	return KERN_SUCCESS;

}