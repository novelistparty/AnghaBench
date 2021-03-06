#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct stack {size_t sp; TYPE_2__* stack; } ;
struct number {int dummy; } ;
struct TYPE_3__ {struct number* num; } ;
struct TYPE_4__ {scalar_t__ type; TYPE_1__ u; int /*<<< orphan*/ * array; } ;

/* Variables and functions */
 scalar_t__ BCODE_NUMBER ; 
 int /*<<< orphan*/  array_free (int /*<<< orphan*/ *) ; 
 scalar_t__ stack_empty (struct stack*) ; 
 int /*<<< orphan*/  warnx (char*) ; 

struct number *
stack_popnumber(struct stack *stack)
{

	if (stack_empty(stack))
		return (NULL);
	array_free(stack->stack[stack->sp].array);
	stack->stack[stack->sp].array = NULL;
	if (stack->stack[stack->sp].type != BCODE_NUMBER) {
		warnx("not a number"); /* XXX remove */
		return (NULL);
	}
	return stack->stack[stack->sp--].u.num;
}