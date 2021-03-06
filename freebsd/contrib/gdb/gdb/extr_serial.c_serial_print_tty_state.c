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
struct ui_file {int dummy; } ;
struct serial {TYPE_1__* ops; } ;
typedef  int /*<<< orphan*/  serial_ttystate ;
struct TYPE_2__ {int /*<<< orphan*/  (* print_tty_state ) (struct serial*,int /*<<< orphan*/ ,struct ui_file*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct serial*,int /*<<< orphan*/ ,struct ui_file*) ; 

void
serial_print_tty_state (struct serial *scb,
			serial_ttystate ttystate,
			struct ui_file *stream)
{
  scb->ops->print_tty_state (scb, ttystate, stream);
}