#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ast_t ;
struct TYPE_2__ {int /*<<< orphan*/  cpu_pending_ast; } ;

/* Variables and functions */
 TYPE_1__* getCpuDatap () ; 

ast_t *
ast_pending(void)
{
	return (&getCpuDatap()->cpu_pending_ast);
}