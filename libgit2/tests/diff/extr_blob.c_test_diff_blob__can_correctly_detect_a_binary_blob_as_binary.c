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
 int /*<<< orphan*/  alien ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_blob_is_binary (int /*<<< orphan*/ ) ; 

void test_diff_blob__can_correctly_detect_a_binary_blob_as_binary(void)
{
	/* alien.png */
	cl_assert_equal_i(true, git_blob_is_binary(alien));
}