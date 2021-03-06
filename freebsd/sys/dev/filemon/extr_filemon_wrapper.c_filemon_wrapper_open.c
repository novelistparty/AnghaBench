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
struct thread {int dummy; } ;
struct open_args {int /*<<< orphan*/  flags; int /*<<< orphan*/  path; } ;

/* Variables and functions */
 int /*<<< orphan*/  AT_FDCWD ; 
 int /*<<< orphan*/  _filemon_wrapper_openat (struct thread*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sys_open (struct thread*,struct open_args*) ; 

__attribute__((used)) static int
filemon_wrapper_open(struct thread *td, struct open_args *uap)
{
	int ret;

	if ((ret = sys_open(td, uap)) == 0)
		_filemon_wrapper_openat(td, uap->path, uap->flags, AT_FDCWD);

	return (ret);
}