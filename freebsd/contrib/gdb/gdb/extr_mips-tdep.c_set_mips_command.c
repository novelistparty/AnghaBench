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

/* Variables and functions */
 int /*<<< orphan*/  all_commands ; 
 int /*<<< orphan*/  gdb_stdout ; 
 int /*<<< orphan*/  help_list (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf_unfiltered (char*) ; 
 int /*<<< orphan*/  setmipscmdlist ; 

__attribute__((used)) static void
set_mips_command (char *args, int from_tty)
{
  printf_unfiltered
    ("\"set mips\" must be followed by an appropriate subcommand.\n");
  help_list (setmipscmdlist, "set mips ", all_commands, gdb_stdout);
}