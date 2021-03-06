#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int num; char const** arg; } ;
typedef  TYPE_1__ riscv_args_t ;

/* Variables and functions */
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static const char* arg_n(riscv_args_t* args, int n) {
	if (n >= args->num || !strcmp (args->arg[n], "zero")) {
		return "0";
	}
	return args->arg[n];
}