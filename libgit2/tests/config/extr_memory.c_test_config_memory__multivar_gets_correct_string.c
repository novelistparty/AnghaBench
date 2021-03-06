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
 int /*<<< orphan*/  assert_config_contains (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  backend ; 
 int /*<<< orphan*/  setup_backend (char*) ; 

void test_config_memory__multivar_gets_correct_string(void)
{
	setup_backend(
		"[general]\n"
		"foo=bar1\n"
		"foo=bar2\n");
	assert_config_contains(backend, "general.foo", "bar2");
}