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
 scalar_t__ pipe (int*) ; 

__attribute__((used)) static int
pipe_create(int *fd1p, int *fd2p)
{
	int fds[2];

	if (pipe(fds) < 0)
		return (-1);

	*fd1p = fds[0];
	*fd2p = fds[1];

	return (0);
}