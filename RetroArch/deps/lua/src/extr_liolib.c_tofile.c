#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_4__ {int /*<<< orphan*/ * f; } ;
typedef  TYPE_1__ LStream ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ isclosed (TYPE_1__*) ; 
 int /*<<< orphan*/  luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_assert (int /*<<< orphan*/ *) ; 
 TYPE_1__* tolstream (int /*<<< orphan*/ *) ; 

__attribute__((used)) static FILE *tofile (lua_State *L) {
  LStream *p = tolstream(L);
  if (isclosed(p))
    luaL_error(L, "attempt to use a closed file");
  lua_assert(p->f);
  return p->f;
}