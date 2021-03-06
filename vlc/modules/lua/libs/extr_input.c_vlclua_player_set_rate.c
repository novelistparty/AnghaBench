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
typedef  int /*<<< orphan*/  vlc_player_t ;
typedef  int /*<<< orphan*/  lua_State ;

/* Variables and functions */
 float luaL_checknumber (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  vlc_player_ChangeRate (int /*<<< orphan*/ *,float) ; 
 int /*<<< orphan*/  vlc_player_Lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_player_Unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * vlclua_get_player_internal (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int vlclua_player_set_rate(lua_State *L)
{
    vlc_player_t *player = vlclua_get_player_internal(L);

    float rate = luaL_checknumber(L, 1);

    vlc_player_Lock(player);
    vlc_player_ChangeRate(player, rate);
    vlc_player_Unlock(player);

    return 0;
}