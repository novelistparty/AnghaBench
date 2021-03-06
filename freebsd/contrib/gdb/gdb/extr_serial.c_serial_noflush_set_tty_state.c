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
struct serial {TYPE_1__* ops; } ;
typedef  int /*<<< orphan*/  serial_ttystate ;
struct TYPE_2__ {int (* noflush_set_tty_state ) (struct serial*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (struct serial*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
serial_noflush_set_tty_state (struct serial *scb,
			      serial_ttystate new_ttystate,
			      serial_ttystate old_ttystate)
{
  return scb->ops->noflush_set_tty_state (scb, new_ttystate, old_ttystate);
}