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
 int /*<<< orphan*/  dump_solution_for_var (int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  stdout ; 

void
debug_solution_for_var (unsigned int var)
{
  dump_solution_for_var (stdout, var);
}