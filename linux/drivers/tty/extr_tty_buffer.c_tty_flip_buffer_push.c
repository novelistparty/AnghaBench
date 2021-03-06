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
struct tty_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  tty_schedule_flip (struct tty_port*) ; 

void tty_flip_buffer_push(struct tty_port *port)
{
	tty_schedule_flip(port);
}