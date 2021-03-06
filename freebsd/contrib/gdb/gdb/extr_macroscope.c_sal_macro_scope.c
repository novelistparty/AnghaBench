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
struct symtab_and_line {int line; TYPE_1__* symtab; } ;
struct macro_source_file {int dummy; } ;
struct macro_scope {int line; struct macro_source_file* file; } ;
struct TYPE_2__ {int /*<<< orphan*/  filename; int /*<<< orphan*/  macro_table; } ;

/* Variables and functions */
 int /*<<< orphan*/  complaint (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 struct macro_source_file* macro_lookup_inclusion (struct macro_source_file*,int /*<<< orphan*/ ) ; 
 struct macro_source_file* macro_main (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  symfile_complaints ; 
 scalar_t__ xmalloc (int) ; 

struct macro_scope *
sal_macro_scope (struct symtab_and_line sal)
{
  struct macro_source_file *main, *inclusion;
  struct macro_scope *ms;

  if (! sal.symtab
      || ! sal.symtab->macro_table)
    return 0;

  ms = (struct macro_scope *) xmalloc (sizeof (*ms));

  main = macro_main (sal.symtab->macro_table);
  inclusion = macro_lookup_inclusion (main, sal.symtab->filename);

  if (inclusion)
    {
      ms->file = inclusion;
      ms->line = sal.line;
    }
  else
    {
      /* There are, unfortunately, cases where a compilation unit can
         have a symtab for a source file that doesn't appear in the
         macro table.  For example, at the moment, Dwarf doesn't have
         any way in the .debug_macinfo section to describe the effect
         of #line directives, so if you debug a YACC parser you'll get
         a macro table which only mentions the .c files generated by
         YACC, but symtabs that mention the .y files consumed by YACC.

         In the long run, we should extend the Dwarf macro info
         representation to handle #line directives, and get GCC to
         emit it.

         For the time being, though, we'll just treat these as
         occurring at the end of the main source file.  */
      ms->file = main;
      ms->line = -1;

      complaint (&symfile_complaints,
                 "symtab found for `%s', but that file\n"
                 "is not covered in the compilation unit's macro information",
                 sal.symtab->filename);
    }

  return ms;
}