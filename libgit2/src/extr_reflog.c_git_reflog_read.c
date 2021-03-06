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
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_reflog ;
typedef  int /*<<< orphan*/  git_refdb ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int git_refdb_reflog_read (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int git_repository_refdb__weakptr (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

int git_reflog_read(git_reflog **reflog, git_repository *repo,  const char *name)
{
	git_refdb *refdb;
	int error;

	assert(reflog && repo && name);

	if ((error = git_repository_refdb__weakptr(&refdb, repo)) < 0)
		return error;

	return git_refdb_reflog_read(reflog, refdb, name);
}