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
struct il_priv {int /*<<< orphan*/  alive_start; int /*<<< orphan*/  init_alive_start; } ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_delayed_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cancel_delayed_work_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  il3945_hw_cancel_deferred_work (struct il_priv*) ; 
 int /*<<< orphan*/  il_cancel_scan_deferred_work (struct il_priv*) ; 

__attribute__((used)) static void
il3945_cancel_deferred_work(struct il_priv *il)
{
	il3945_hw_cancel_deferred_work(il);

	cancel_delayed_work_sync(&il->init_alive_start);
	cancel_delayed_work(&il->alive_start);

	il_cancel_scan_deferred_work(il);
}