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
struct il_priv {int /*<<< orphan*/  mutex; } ;

/* Variables and functions */
 int il4965_static_wepkey_cmd (struct il_priv*,int) ; 
 int /*<<< orphan*/  lockdep_assert_held (int /*<<< orphan*/ *) ; 

int
il4965_restore_default_wep_keys(struct il_priv *il)
{
	lockdep_assert_held(&il->mutex);

	return il4965_static_wepkey_cmd(il, false);
}