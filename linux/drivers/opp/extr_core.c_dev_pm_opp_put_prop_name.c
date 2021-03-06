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
struct opp_table {int /*<<< orphan*/ * prop_name; int /*<<< orphan*/  opp_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  dev_pm_opp_put_opp_table (struct opp_table*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_empty (int /*<<< orphan*/ *) ; 

void dev_pm_opp_put_prop_name(struct opp_table *opp_table)
{
	/* Make sure there are no concurrent readers while updating opp_table */
	WARN_ON(!list_empty(&opp_table->opp_list));

	kfree(opp_table->prop_name);
	opp_table->prop_name = NULL;

	dev_pm_opp_put_opp_table(opp_table);
}