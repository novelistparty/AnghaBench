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
 int /*<<< orphan*/  cl_fixture_cleanup (char*) ; 
 int /*<<< orphan*/  cl_git_sandbox_cleanup () ; 
 int /*<<< orphan*/  g_remote ; 
 int /*<<< orphan*/  g_repo_b ; 
 int /*<<< orphan*/  git_remote_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_repository_free (int /*<<< orphan*/ ) ; 

void test_network_remote_defaultbranch__cleanup(void)
{
	git_remote_free(g_remote);
	git_repository_free(g_repo_b);

	cl_git_sandbox_cleanup();
	cl_fixture_cleanup("repo-b.git");
}