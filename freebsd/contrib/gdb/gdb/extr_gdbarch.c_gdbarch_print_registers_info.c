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
struct ui_file {int dummy; } ;
struct gdbarch {int /*<<< orphan*/  (* print_registers_info ) (struct gdbarch*,struct ui_file*,struct frame_info*,int,int) ;} ;
struct frame_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf_unfiltered (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gdb_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gdb_stdlog ; 
 int gdbarch_debug ; 
 int /*<<< orphan*/  stub1 (struct gdbarch*,struct ui_file*,struct frame_info*,int,int) ; 

void
gdbarch_print_registers_info (struct gdbarch *gdbarch, struct ui_file *file, struct frame_info *frame, int regnum, int all)
{
  gdb_assert (gdbarch != NULL);
  gdb_assert (gdbarch->print_registers_info != NULL);
  if (gdbarch_debug >= 2)
    fprintf_unfiltered (gdb_stdlog, "gdbarch_print_registers_info called\n");
  gdbarch->print_registers_info (gdbarch, file, frame, regnum, all);
}