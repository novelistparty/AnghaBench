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
 int /*<<< orphan*/  assert_commit_fails (char const*,int /*<<< orphan*/ ) ; 

void test_object_commit_parse__parsing_commit_without_tree_fails(void)
{
	const char *commit =
		"author Author <author@example.com>\n"
		"committer Committer <committer@example.com>\n"
		"\n"
		"Message";
	assert_commit_fails(commit, 0);
}