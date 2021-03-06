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
 int X86_CR4_PGE ; 
 int read_cr4 () ; 
 int /*<<< orphan*/  write_cr4 (int) ; 

__attribute__((used)) static void adjust_pge(void *on)
{
	if (on)
		write_cr4(read_cr4() | X86_CR4_PGE);
	else
		write_cr4(read_cr4() & ~X86_CR4_PGE);
}