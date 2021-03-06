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
struct device_node {int dummy; } ;

/* Variables and functions */
 struct device_node* of_get_next_parent (struct device_node*) ; 
 struct device_node* of_graph_get_remote_endpoint (struct device_node const*) ; 

struct device_node *of_graph_get_remote_port(const struct device_node *node)
{
	struct device_node *np;

	/* Get remote endpoint node. */
	np = of_graph_get_remote_endpoint(node);
	if (!np)
		return NULL;
	return of_get_next_parent(np);
}