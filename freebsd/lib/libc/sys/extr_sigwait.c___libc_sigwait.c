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
typedef  int /*<<< orphan*/  sigset_t ;

/* Variables and functions */
 int EINTR ; 
 int __sys_sigwait (int /*<<< orphan*/  const*,int*) ; 

int
__libc_sigwait(const sigset_t *set, int *sig)
{
	int ret;

	/* POSIX does not allow EINTR to be returned */
	do  {
		ret = __sys_sigwait(set, sig);
	} while (ret == EINTR);
	return (ret);
}