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
typedef  int /*<<< orphan*/  subsegT ;
typedef  int /*<<< orphan*/  segT ;

/* Variables and functions */
 scalar_t__ IS_ELF ; 
 char* RDATA_SECTION_NAME ; 
 int SEC_ALLOC ; 
 int SEC_DATA ; 
 int SEC_LOAD ; 
 int SEC_READONLY ; 
 int SEC_RELOC ; 
 int /*<<< orphan*/  TARGET_OS ; 
 int auto_align ; 
 int /*<<< orphan*/  bfd_set_section_flags (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  bss_section ; 
 int /*<<< orphan*/  demand_empty_rest_of_line () ; 
 int /*<<< orphan*/  get_absolute_expression () ; 
 int /*<<< orphan*/  mips_emit_delays () ; 
 int /*<<< orphan*/  obj_elf_section_change_hook () ; 
 int /*<<< orphan*/  record_alignment (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  s_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s_text (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stdoutput ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  subseg_new (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  subseg_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
s_change_sec (int sec)
{
  segT seg;

#ifdef OBJ_ELF
  /* The ELF backend needs to know that we are changing sections, so
     that .previous works correctly.  We could do something like check
     for an obj_section_change_hook macro, but that might be confusing
     as it would not be appropriate to use it in the section changing
     functions in read.c, since obj-elf.c intercepts those.  FIXME:
     This should be cleaner, somehow.  */
  if (IS_ELF)
    obj_elf_section_change_hook ();
#endif

  mips_emit_delays ();
  switch (sec)
    {
    case 't':
      s_text (0);
      break;
    case 'd':
      s_data (0);
      break;
    case 'b':
      subseg_set (bss_section, (subsegT) get_absolute_expression ());
      demand_empty_rest_of_line ();
      break;

    case 'r':
      seg = subseg_new (RDATA_SECTION_NAME,
			(subsegT) get_absolute_expression ());
      if (IS_ELF)
	{
	  bfd_set_section_flags (stdoutput, seg, (SEC_ALLOC | SEC_LOAD
						  | SEC_READONLY | SEC_RELOC
						  | SEC_DATA));
	  if (strcmp (TARGET_OS, "elf") != 0)
	    record_alignment (seg, 4);
	}
      demand_empty_rest_of_line ();
      break;

    case 's':
      seg = subseg_new (".sdata", (subsegT) get_absolute_expression ());
      if (IS_ELF)
	{
	  bfd_set_section_flags (stdoutput, seg,
				 SEC_ALLOC | SEC_LOAD | SEC_RELOC | SEC_DATA);
	  if (strcmp (TARGET_OS, "elf") != 0)
	    record_alignment (seg, 4);
	}
      demand_empty_rest_of_line ();
      break;
    }

  auto_align = 1;
}