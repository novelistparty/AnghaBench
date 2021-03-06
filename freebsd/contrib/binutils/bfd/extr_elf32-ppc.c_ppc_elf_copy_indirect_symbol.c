#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {struct plt_entry* plist; } ;
struct TYPE_8__ {scalar_t__ refcount; } ;
struct TYPE_7__ {scalar_t__ type; } ;
struct TYPE_11__ {int dynindx; scalar_t__ dynstr_index; TYPE_4__ plt; TYPE_2__ got; TYPE_1__ root; int /*<<< orphan*/  needs_plt; int /*<<< orphan*/  ref_regular_nonweak; int /*<<< orphan*/  ref_regular; int /*<<< orphan*/  ref_dynamic; int /*<<< orphan*/  non_got_ref; scalar_t__ dynamic_adjusted; } ;
struct ppc_elf_link_hash_entry {TYPE_5__ elf; int /*<<< orphan*/  has_sda_refs; int /*<<< orphan*/  tls_mask; struct ppc_elf_dyn_relocs* dyn_relocs; } ;
struct ppc_elf_dyn_relocs {scalar_t__ sec; struct ppc_elf_dyn_relocs* next; scalar_t__ count; scalar_t__ pc_count; } ;
struct TYPE_9__ {scalar_t__ refcount; } ;
struct plt_entry {scalar_t__ sec; scalar_t__ addend; struct plt_entry* next; TYPE_3__ plt; } ;
struct elf_link_hash_entry {int dummy; } ;
struct bfd_link_info {int dummy; } ;
struct TYPE_12__ {int /*<<< orphan*/  dynstr; } ;

/* Variables and functions */
 scalar_t__ ELIMINATE_COPY_RELOCS ; 
 int /*<<< orphan*/  _bfd_elf_strtab_delref (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ bfd_link_hash_indirect ; 
 TYPE_6__* elf_hash_table (struct bfd_link_info*) ; 

__attribute__((used)) static void
ppc_elf_copy_indirect_symbol (struct bfd_link_info *info,
			      struct elf_link_hash_entry *dir,
			      struct elf_link_hash_entry *ind)
{
  struct ppc_elf_link_hash_entry *edir, *eind;

  edir = (struct ppc_elf_link_hash_entry *) dir;
  eind = (struct ppc_elf_link_hash_entry *) ind;

  if (eind->dyn_relocs != NULL)
    {
      if (edir->dyn_relocs != NULL)
	{
	  struct ppc_elf_dyn_relocs **pp;
	  struct ppc_elf_dyn_relocs *p;

	  /* Add reloc counts against the indirect sym to the direct sym
	     list.  Merge any entries against the same section.  */
	  for (pp = &eind->dyn_relocs; (p = *pp) != NULL; )
	    {
	      struct ppc_elf_dyn_relocs *q;

	      for (q = edir->dyn_relocs; q != NULL; q = q->next)
		if (q->sec == p->sec)
		  {
		    q->pc_count += p->pc_count;
		    q->count += p->count;
		    *pp = p->next;
		    break;
		  }
	      if (q == NULL)
		pp = &p->next;
	    }
	  *pp = edir->dyn_relocs;
	}

      edir->dyn_relocs = eind->dyn_relocs;
      eind->dyn_relocs = NULL;
    }

  edir->tls_mask |= eind->tls_mask;
  edir->has_sda_refs |= eind->has_sda_refs;

  /* If called to transfer flags for a weakdef during processing
     of elf_adjust_dynamic_symbol, don't copy non_got_ref.
     We clear it ourselves for ELIMINATE_COPY_RELOCS.  */
  if (!(ELIMINATE_COPY_RELOCS
	&& eind->elf.root.type != bfd_link_hash_indirect
	&& edir->elf.dynamic_adjusted))
    edir->elf.non_got_ref |= eind->elf.non_got_ref;

  edir->elf.ref_dynamic |= eind->elf.ref_dynamic;
  edir->elf.ref_regular |= eind->elf.ref_regular;
  edir->elf.ref_regular_nonweak |= eind->elf.ref_regular_nonweak;
  edir->elf.needs_plt |= eind->elf.needs_plt;

  /* If we were called to copy over info for a weak sym, that's all.  */
  if (eind->elf.root.type != bfd_link_hash_indirect)
    return;

  /* Copy over the GOT refcount entries that we may have already seen to
     the symbol which just became indirect.  */
  edir->elf.got.refcount += eind->elf.got.refcount;
  eind->elf.got.refcount = 0;

  /* And plt entries.  */
  if (eind->elf.plt.plist != NULL)
    {
      if (edir->elf.plt.plist != NULL)
	{
	  struct plt_entry **entp;
	  struct plt_entry *ent;

	  for (entp = &eind->elf.plt.plist; (ent = *entp) != NULL; )
	    {
	      struct plt_entry *dent;

	      for (dent = edir->elf.plt.plist; dent != NULL; dent = dent->next)
		if (dent->sec == ent->sec && dent->addend == ent->addend)
		  {
		    dent->plt.refcount += ent->plt.refcount;
		    *entp = ent->next;
		    break;
		  }
	      if (dent == NULL)
		entp = &ent->next;
	    }
	  *entp = edir->elf.plt.plist;
	}

      edir->elf.plt.plist = eind->elf.plt.plist;
      eind->elf.plt.plist = NULL;
    }

  if (eind->elf.dynindx != -1)
    {
      if (edir->elf.dynindx != -1)
	_bfd_elf_strtab_delref (elf_hash_table (info)->dynstr,
				edir->elf.dynstr_index);
      edir->elf.dynindx = eind->elf.dynindx;
      edir->elf.dynstr_index = eind->elf.dynstr_index;
      eind->elf.dynindx = -1;
      eind->elf.dynstr_index = 0;
    }
}