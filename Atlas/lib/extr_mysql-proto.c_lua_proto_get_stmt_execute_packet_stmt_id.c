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
struct TYPE_4__ {scalar_t__ offset; TYPE_2__* data; } ;
typedef  TYPE_1__ network_packet ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  guint32 ;
struct TYPE_5__ {char* str; size_t len; } ;
typedef  TYPE_2__ GString ;

/* Variables and functions */
 int /*<<< orphan*/  G_STRLOC ; 
 char* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int /*<<< orphan*/  luaL_error (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lua_pushinteger (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ network_mysqld_proto_get_stmt_execute_packet_stmt_id (TYPE_1__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int lua_proto_get_stmt_execute_packet_stmt_id (lua_State *L) {
	size_t packet_len;
	const char *packet_str = luaL_checklstring(L, 1, &packet_len);
	network_packet packet;
	GString s;
	int err = 0;
	guint32 stmt_id;

	s.str = (char *)packet_str;
	s.len = packet_len;

	packet.data = &s;
	packet.offset = 0;

	err = err || network_mysqld_proto_get_stmt_execute_packet_stmt_id(&packet, &stmt_id);
	if (err) {
		luaL_error(L, "%s: network_mysqld_proto_get_stmt_execute_packet_stmt_id() failed", G_STRLOC);
		return 0;
	}

	lua_pushinteger(L, stmt_id);

	return 1;
}