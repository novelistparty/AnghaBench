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
 scalar_t__ gentables ; 

__attribute__((used)) static const char *get_int16_decl (void)
{
	return (gentables)
		? "static yyconst flex_int16_t %s[%d] =\n    {   0,\n"
		: "static yyconst flex_int16_t * %s = 0;\n";
}