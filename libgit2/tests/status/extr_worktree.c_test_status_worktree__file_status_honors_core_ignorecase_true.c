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
 int /*<<< orphan*/  GIT_STATUS_CURRENT ; 
 int /*<<< orphan*/  assert_ignore_case (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void test_status_worktree__file_status_honors_core_ignorecase_true(void)
{
	assert_ignore_case(true, GIT_STATUS_CURRENT, GIT_STATUS_CURRENT);
}