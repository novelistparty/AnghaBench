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
typedef  int /*<<< orphan*/  extent_node_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/ * chunk_lookup (void const*,int) ; 
 int /*<<< orphan*/  extent_node_achunk_get (int /*<<< orphan*/ *) ; 

__attribute__((used)) static extent_node_t *
huge_node_get(const void *ptr)
{
	extent_node_t *node;

	node = chunk_lookup(ptr, true);
	assert(!extent_node_achunk_get(node));

	return (node);
}