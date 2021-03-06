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
typedef  int /*<<< orphan*/  git_signature ;
typedef  int /*<<< orphan*/  git_repository ;
typedef  int /*<<< orphan*/  git_index ;

/* Variables and functions */
 int /*<<< orphan*/  cl_git_mkfile (char*,char*) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_rewritefile (char*,char*) ; 
 int /*<<< orphan*/  cl_repo_commit_from_index (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  git_index_add_bypath (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_index_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_index_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_repository_index (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 

void setup_stash(git_repository *repo, git_signature *signature)
{
	git_index *index;

	cl_git_pass(git_repository_index(&index, repo));

	cl_git_mkfile("stash/what", "hello\n");		/* ce013625030ba8dba906f756967f9e9ca394464a */
	cl_git_mkfile("stash/how", "small\n");		/* ac790413e2d7a26c3767e78c57bb28716686eebc */
	cl_git_mkfile("stash/who", "world\n");		/* cc628ccd10742baea8241c5924df992b5c019f71 */
	cl_git_mkfile("stash/when", "now\n");		/* b6ed15e81e2593d7bb6265eb4a991d29dc3e628b */
	cl_git_mkfile("stash/just.ignore", "me\n");	/* 78925fb1236b98b37a35e9723033e627f97aa88b */

	cl_git_mkfile("stash/.gitignore", "*.ignore\n");

	cl_git_pass(git_index_add_bypath(index, "what"));
	cl_git_pass(git_index_add_bypath(index, "how"));
	cl_git_pass(git_index_add_bypath(index, "who"));
	cl_git_pass(git_index_add_bypath(index, ".gitignore"));

	cl_repo_commit_from_index(NULL, repo, signature, 0, "Initial commit");

	cl_git_rewritefile("stash/what", "goodbye\n");			/* dd7e1c6f0fefe118f0b63d9f10908c460aa317a6 */
	cl_git_rewritefile("stash/how", "not so small and\n");	/* e6d64adb2c7f3eb8feb493b556cc8070dca379a3 */
	cl_git_rewritefile("stash/who", "funky world\n");		/* a0400d4954659306a976567af43125a0b1aa8595 */
	cl_git_mkfile("stash/why", "would anybody use stash?\n"); /* 88c2533e21f098b89c91a431d8075cbde422a51 */
	cl_git_mkfile("stash/where", "????\n");					/* e08f7fbb9a42a0c5367cf8b349f1f08c3d56bd72 */

	cl_git_pass(git_index_add_bypath(index, "what"));
	cl_git_pass(git_index_add_bypath(index, "how"));
	cl_git_pass(git_index_add_bypath(index, "why"));
	cl_git_pass(git_index_add_bypath(index, "where"));
	cl_git_pass(git_index_write(index));

	cl_git_rewritefile("stash/what", "see you later\n");	/* bc99dc98b3eba0e9157e94769cd4d49cb49de449 */
	cl_git_mkfile("stash/where", "....\n");					/* e3d6434ec12eb76af8dfa843a64ba6ab91014a0b */

	git_index_free(index);
}