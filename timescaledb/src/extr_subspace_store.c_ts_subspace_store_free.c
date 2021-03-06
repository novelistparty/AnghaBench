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
struct TYPE_4__ {int /*<<< orphan*/  origin; } ;
typedef  TYPE_1__ SubspaceStore ;

/* Variables and functions */
 int /*<<< orphan*/  pfree (TYPE_1__*) ; 
 int /*<<< orphan*/  subspace_store_internal_node_free (int /*<<< orphan*/ ) ; 

void
ts_subspace_store_free(SubspaceStore *store)
{
	subspace_store_internal_node_free(store->origin);
	pfree(store);
}