#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct efx_nic {struct efx_filter_state* filter_state; } ;
struct efx_filter_state {struct efx_filter_state* rps_flow_id; TYPE_1__* table; } ;
typedef  enum efx_filter_table_id { ____Placeholder_efx_filter_table_id } efx_filter_table_id ;
struct TYPE_2__ {int /*<<< orphan*/  spec; struct efx_filter_state* used_bitmap; } ;

/* Variables and functions */
 int EFX_FILTER_TABLE_COUNT ; 
 int /*<<< orphan*/  kfree (struct efx_filter_state*) ; 
 int /*<<< orphan*/  vfree (int /*<<< orphan*/ ) ; 

void efx_remove_filters(struct efx_nic *efx)
{
	struct efx_filter_state *state = efx->filter_state;
	enum efx_filter_table_id table_id;

	for (table_id = 0; table_id < EFX_FILTER_TABLE_COUNT; table_id++) {
		kfree(state->table[table_id].used_bitmap);
		vfree(state->table[table_id].spec);
	}
#ifdef CONFIG_RFS_ACCEL
	kfree(state->rps_flow_id);
#endif
	kfree(state);
}