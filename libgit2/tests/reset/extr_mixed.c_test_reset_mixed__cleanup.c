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
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  git_object_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * target ; 

void test_reset_mixed__cleanup(void)
{
	git_object_free(target);
	target = NULL;

	cl_git_sandbox_cleanup();
}