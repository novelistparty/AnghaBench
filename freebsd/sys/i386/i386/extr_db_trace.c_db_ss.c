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
struct db_variable {int dummy; } ;
typedef  int /*<<< orphan*/  db_expr_t ;
struct TYPE_3__ {int /*<<< orphan*/  tf_ss; } ;

/* Variables and functions */
 int DB_VAR_GET ; 
 scalar_t__ TF_HAS_STACKREGS (TYPE_1__*) ; 
 TYPE_1__* kdb_frame ; 
 int /*<<< orphan*/  rss () ; 

__attribute__((used)) static int
db_ss(struct db_variable *vp, db_expr_t *valuep, int op)
{

	if (kdb_frame == NULL)
		return (0);

	if (op == DB_VAR_GET)
		*valuep = TF_HAS_STACKREGS(kdb_frame) ? kdb_frame->tf_ss :
		    rss();
	else if (TF_HAS_STACKREGS(kdb_frame))
		kdb_frame->tf_ss = *valuep;
	return (1);
}