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
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  EXIT_SUCCESS ; 
 int SIGXFSZ ; 
 int /*<<< orphan*/  _exit (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
sighandler(int signo)
{

	if (signo != SIGXFSZ)
		_exit(EXIT_FAILURE);

	_exit(EXIT_SUCCESS);
}