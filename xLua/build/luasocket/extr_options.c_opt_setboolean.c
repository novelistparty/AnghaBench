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
typedef  int /*<<< orphan*/  val ;
typedef  int /*<<< orphan*/  p_socket ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 int auxiliar_checkboolean (int /*<<< orphan*/ *,int) ; 
 int opt_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int,char*,int) ; 

__attribute__((used)) static int opt_setboolean(lua_State *L, p_socket ps, int level, int name)
{
    int val = auxiliar_checkboolean(L, 3);             /* obj, name, bool */
    return opt_set(L, ps, level, name, (char *) &val, sizeof(val));
}