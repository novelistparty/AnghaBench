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
struct ui_out {int dummy; } ;
struct captured_execute_command_args {char* command; int from_tty; } ;
typedef  enum gdb_rc { ____Placeholder_gdb_rc } gdb_rc ;

/* Variables and functions */
 int /*<<< orphan*/  RETURN_MASK_ALL ; 
 int catch_exceptions (struct ui_out*,int /*<<< orphan*/ ,struct captured_execute_command_args*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  do_captured_execute_command ; 

__attribute__((used)) static enum gdb_rc
safe_execute_command (struct ui_out *uiout, char *command, int from_tty)
{
  struct captured_execute_command_args args;
  args.command = command;
  args.from_tty = from_tty;
  return catch_exceptions (uiout, do_captured_execute_command, &args,
			   NULL, RETURN_MASK_ALL);
}