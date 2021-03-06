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
 scalar_t__ atexit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pidfile_cleanup ; 

__attribute__((used)) static int
register_atexit_handler(void)
{
	static bool done = false;

	if (!done) {
		if (atexit(pidfile_cleanup) < 0)
			return -1;
		done = true;
	}

	return 0;
}