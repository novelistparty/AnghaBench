#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {unsigned int hugetlb_pte_count; } ;
struct mm_struct {TYPE_1__ context; } ;
typedef  int /*<<< orphan*/  pte_t ;

/* Variables and functions */
 unsigned long HPAGE_SIZE ; 
 unsigned int PAGE_SHIFT ; 
 unsigned int PMD_SHIFT ; 
 unsigned long PMD_SIZE ; 
 unsigned int PUD_SHIFT ; 
 unsigned long PUD_SIZE ; 
 unsigned long REAL_HPAGE_SIZE ; 
 int /*<<< orphan*/  __pte (scalar_t__) ; 
 unsigned int huge_tte_to_shift (int /*<<< orphan*/ ) ; 
 unsigned long huge_tte_to_size (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  maybe_tlb_batch_add (struct mm_struct*,unsigned long,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 scalar_t__ pte_none (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_present (int /*<<< orphan*/ ) ; 
 scalar_t__ pte_val (int /*<<< orphan*/ ) ; 

void set_huge_pte_at(struct mm_struct *mm, unsigned long addr,
		     pte_t *ptep, pte_t entry)
{
	unsigned int nptes, orig_shift, shift;
	unsigned long i, size;
	pte_t orig;

	size = huge_tte_to_size(entry);

	shift = PAGE_SHIFT;
	if (size >= PUD_SIZE)
		shift = PUD_SHIFT;
	else if (size >= PMD_SIZE)
		shift = PMD_SHIFT;
	else
		shift = PAGE_SHIFT;

	nptes = size >> shift;

	if (!pte_present(*ptep) && pte_present(entry))
		mm->context.hugetlb_pte_count += nptes;

	addr &= ~(size - 1);
	orig = *ptep;
	orig_shift = pte_none(orig) ? PAGE_SHIFT : huge_tte_to_shift(orig);

	for (i = 0; i < nptes; i++)
		ptep[i] = __pte(pte_val(entry) + (i << shift));

	maybe_tlb_batch_add(mm, addr, ptep, orig, 0, orig_shift);
	/* An HPAGE_SIZE'ed page is composed of two REAL_HPAGE_SIZE'ed pages */
	if (size == HPAGE_SIZE)
		maybe_tlb_batch_add(mm, addr + REAL_HPAGE_SIZE, ptep, orig, 0,
				    orig_shift);
}