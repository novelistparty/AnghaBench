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
 int /*<<< orphan*/  f_print (int /*<<< orphan*/ ,char*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fout ; 
 int /*<<< orphan*/  stringfix (char const*) ; 

__attribute__((used)) static void
p_xdrfunc(const char *rname, const char *typename)
{
	f_print(fout, "\t\txdr_%s = (xdrproc_t) xdr_%s;\n",
	    rname, stringfix(typename));
}