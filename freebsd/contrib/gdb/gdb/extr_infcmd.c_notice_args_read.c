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
struct cmd_list_element {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  get_inferior_args () ; 

__attribute__((used)) static void
notice_args_read (char *args, int from_tty, struct cmd_list_element *c)
{
  /* Might compute the value.  */
  get_inferior_args ();
}