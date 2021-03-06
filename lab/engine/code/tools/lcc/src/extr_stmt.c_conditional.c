#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* Tree ;
struct TYPE_7__ {int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int Aflag ; 
 TYPE_1__* cond (TYPE_1__*) ; 
 TYPE_1__* expr (int) ; 
 int /*<<< orphan*/  funcname (TYPE_1__*) ; 
 scalar_t__ isfunc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  warning (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static Tree conditional(int tok) {
	Tree p = expr(tok);

	if (Aflag > 1 && isfunc(p->type))
		warning("%s used in a conditional expression\n",
			funcname(p));
	return cond(p);
}