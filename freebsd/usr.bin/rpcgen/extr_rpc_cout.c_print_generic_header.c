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
 int /*<<< orphan*/  f_print (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  fout ; 

__attribute__((used)) static void
print_generic_header(const char *procname, int pointerp)
{
	f_print(fout, "\n");
	f_print(fout, "bool_t\n");
	f_print(fout, "xdr_%s(", procname);
	f_print(fout, "XDR *xdrs, ");
	f_print(fout, "%s ", procname);
	if (pointerp)
		f_print(fout, "*");
	f_print(fout, "objp)\n{\n\n");
}