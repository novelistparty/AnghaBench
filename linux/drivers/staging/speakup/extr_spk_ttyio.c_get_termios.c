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
struct ktermios {int dummy; } ;
struct tty_struct {int /*<<< orphan*/  termios_rwsem; struct ktermios termios; } ;

/* Variables and functions */
 int /*<<< orphan*/  down_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void get_termios(struct tty_struct *tty,
			       struct ktermios *out_termios)
{
	down_read(&tty->termios_rwsem);
	*out_termios = tty->termios;
	up_read(&tty->termios_rwsem);
}