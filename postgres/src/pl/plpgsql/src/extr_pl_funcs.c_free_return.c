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
struct TYPE_3__ {int /*<<< orphan*/  expr; } ;
typedef  TYPE_1__ PLpgSQL_stmt_return ;

/* Variables and functions */
 int /*<<< orphan*/  free_expr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
free_return(PLpgSQL_stmt_return *stmt)
{
	free_expr(stmt->expr);
}