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
 int FD_CLOEXEC ; 
 int /*<<< orphan*/  F_GETFD ; 
 int /*<<< orphan*/  F_SETFD ; 
 int fcntl (int,int /*<<< orphan*/ ,...) ; 

void
__archive_ensure_cloexec_flag(int fd)
{
#if defined(_WIN32) && !defined(__CYGWIN__)
	(void)fd; /* UNUSED */
#else
	int flags;

	if (fd >= 0) {
		flags = fcntl(fd, F_GETFD);
		if (flags != -1 && (flags & FD_CLOEXEC) == 0)
			fcntl(fd, F_SETFD, flags | FD_CLOEXEC);
	}
#endif
}