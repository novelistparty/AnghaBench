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
struct cgraph_node {int /*<<< orphan*/ * aux; struct cgraph_node* next; } ;

/* Variables and functions */
 struct cgraph_node* cgraph_nodes ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 

void
ipa_nodes_free (void)
{
  struct cgraph_node *node;

  for (node = cgraph_nodes; node; node = node->next)
    {
      free (node->aux);
      node->aux = NULL;
    }
}