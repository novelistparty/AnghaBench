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
 int boot_parse_arg (char*) ; 

int
boot_parse_args(int argc, char *argv[])
{
        int i, howto;

	howto = 0;
        for (i = 1; i < argc; i++)
                howto |= boot_parse_arg(argv[i]);
	return (howto);
}