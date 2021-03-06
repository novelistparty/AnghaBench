#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ top; scalar_t__ stack_last; scalar_t__ stack; TYPE_2__* ci; } ;
typedef  TYPE_1__ lua_State ;
struct TYPE_5__ {scalar_t__ top; struct TYPE_5__* previous; } ;
typedef  scalar_t__ StkId ;
typedef  TYPE_2__ CallInfo ;

/* Variables and functions */
 int cast_int (scalar_t__) ; 
 int /*<<< orphan*/  lua_assert (int) ; 

__attribute__((used)) static int stackinuse (lua_State *L) {
  CallInfo *ci;
  StkId lim = L->top;
  for (ci = L->ci; ci != NULL; ci = ci->previous) {
    if (lim < ci->top) lim = ci->top;
  }
  lua_assert(lim <= L->stack_last);
  return cast_int(lim - L->stack) + 1;  /* part of stack in use */
}