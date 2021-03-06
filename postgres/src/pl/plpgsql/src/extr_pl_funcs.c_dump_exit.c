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
struct TYPE_3__ {char* label; int /*<<< orphan*/ * cond; scalar_t__ is_exit; } ;
typedef  TYPE_1__ PLpgSQL_stmt_exit ;

/* Variables and functions */
 int /*<<< orphan*/  dump_expr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dump_ind () ; 
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static void
dump_exit(PLpgSQL_stmt_exit *stmt)
{
	dump_ind();
	printf("%s", stmt->is_exit ? "EXIT" : "CONTINUE");
	if (stmt->label != NULL)
		printf(" label='%s'", stmt->label);
	if (stmt->cond != NULL)
	{
		printf(" WHEN ");
		dump_expr(stmt->cond);
	}
	printf("\n");
}