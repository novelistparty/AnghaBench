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
 int /*<<< orphan*/  OK ; 
 int check_arg_count (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  noqiflush () ; 
 int /*<<< orphan*/  report_count (int) ; 
 int /*<<< orphan*/  report_return (int /*<<< orphan*/ ) ; 

void
cmd_noqiflush(int nargs, char **args)
{
	if (check_arg_count(nargs, 0) == 1)
		return;

	noqiflush();
	report_count(1);
	report_return(OK); /* fake a return, the call returns void */
}