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
struct TYPE_4__ {scalar_t__ state; int /*<<< orphan*/ * db_scheduler_handle; } ;
typedef  TYPE_1__ DbHashEntry ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 scalar_t__ DISABLED ; 
 int /*<<< orphan*/  ENABLED ; 
 int /*<<< orphan*/  scheduler_modify_state (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
scheduler_state_trans_disabled_to_enabled(DbHashEntry *entry)
{
	Assert(entry->state == DISABLED);
	Assert(entry->db_scheduler_handle == NULL);
	scheduler_modify_state(entry, ENABLED);
}