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
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  remote_fileio_errno_to_target (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  remote_fileio_reply (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
remote_fileio_return_errno (int retcode)
{
  remote_fileio_reply (retcode,
		       retcode < 0 ? remote_fileio_errno_to_target (errno) : 0);
}