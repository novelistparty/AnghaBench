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
typedef  enum mi_cmd_result { ____Placeholder_mi_cmd_result } mi_cmd_result ;

/* Variables and functions */
 int MI_CMD_DONE ; 
 int /*<<< orphan*/  error (char*) ; 
 int /*<<< orphan*/  select_frame_command (char*,int) ; 
 int /*<<< orphan*/  target_has_stack ; 

enum mi_cmd_result
mi_cmd_stack_select_frame (char *command, char **argv, int argc)
{
  if (!target_has_stack)
    error ("mi_cmd_stack_select_frame: No stack.");

  if (argc > 1)
    error ("mi_cmd_stack_select_frame: Usage: [FRAME_SPEC]");

  /* with no args, don't change frame */
  if (argc == 0)
    select_frame_command (0, 1 /* not used */ );
  else
    select_frame_command (argv[0], 1 /* not used */ );
  return MI_CMD_DONE;
}