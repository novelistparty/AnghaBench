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
 int CMD_OK ; 
 int /*<<< orphan*/  acells ; 
 int /*<<< orphan*/  ofw_memmap (int /*<<< orphan*/ ) ; 

int
command_memmap(int argc, char **argv)
{

	ofw_memmap(acells);
	return (CMD_OK);
}