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
typedef  int /*<<< orphan*/  TrackerServerInfo ;
typedef  int /*<<< orphan*/  FDFSTrunkFullInfo ;
typedef  int /*<<< orphan*/  ConnectionInfo ;

/* Variables and functions */
 scalar_t__ g_if_trunker_self ; 
 int /*<<< orphan*/  tracker_close_connection_ex (int /*<<< orphan*/ *,int) ; 
 int trunk_alloc_space (int const,int /*<<< orphan*/ *) ; 
 int trunk_client_connect_trunk_server (int /*<<< orphan*/ *,int /*<<< orphan*/ **,char*) ; 
 int trunk_client_trunk_do_alloc_space (int /*<<< orphan*/ *,int const,int /*<<< orphan*/ *) ; 

int trunk_client_trunk_alloc_space(const int file_size, \
		FDFSTrunkFullInfo *pTrunkInfo)
{
	int result;
	TrackerServerInfo trunk_server;
	ConnectionInfo *pTrunkServer;

	if (g_if_trunker_self)
	{
		return trunk_alloc_space(file_size, pTrunkInfo);
	}

    if ((result=trunk_client_connect_trunk_server(&trunk_server,
                    &pTrunkServer, "can't alloc trunk space")) != 0)
    {
        return result;
    }

	result = trunk_client_trunk_do_alloc_space(pTrunkServer, \
			file_size, pTrunkInfo);

	tracker_close_connection_ex(pTrunkServer, result != 0);
	return result;
}