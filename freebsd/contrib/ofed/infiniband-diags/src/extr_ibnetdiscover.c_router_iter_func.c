#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct iter_user_data {scalar_t__ group; } ;
struct TYPE_9__ {scalar_t__ remoteport; } ;
typedef  TYPE_2__ ibnd_port_t ;
struct TYPE_10__ {int numports; TYPE_2__** ports; TYPE_1__* chassis; } ;
typedef  TYPE_3__ ibnd_node_t ;
struct TYPE_8__ {scalar_t__ chassisnum; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG (char*,TYPE_3__*) ; 
 int /*<<< orphan*/  out_ca (TYPE_3__*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  out_ca_port (TYPE_2__*,scalar_t__,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void router_iter_func(ibnd_node_t * node, void *iter_user_data)
{
	ibnd_port_t *port;
	int p = 0;
	struct iter_user_data *data = (struct iter_user_data *)iter_user_data;

	DEBUG("RT: node %p\n", node);
	/* Now, skip chassis based RTs */
	if (data->group && node->chassis && node->chassis->chassisnum)
		return;
	out_ca(node, data->group, NULL, NULL, NULL);
	for (p = 1; p <= node->numports; p++) {
		port = node->ports[p];
		if (port && port->remoteport)
			out_ca_port(port, data->group, NULL);
	}
}