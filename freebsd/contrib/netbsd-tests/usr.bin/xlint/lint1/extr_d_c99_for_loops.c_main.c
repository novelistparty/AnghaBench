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
 int /*<<< orphan*/  foo (int) ; 

int
main(void)
{
	// Test the basic functionality
	for (int i = 0; i < 10; i++)
		foo(i);

	// Test that the scope of the iterator is correct
	for (int i = 0; i < 10; i++)
		continue;
	return 0;
}