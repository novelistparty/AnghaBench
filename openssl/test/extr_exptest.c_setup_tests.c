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
 int /*<<< orphan*/  ADD_ALL_TESTS (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ADD_TEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_mod_exp ; 
 int /*<<< orphan*/  test_mod_exp_zero ; 

int setup_tests(void)
{
    ADD_TEST(test_mod_exp_zero);
    ADD_ALL_TESTS(test_mod_exp, 200);
    return 1;
}