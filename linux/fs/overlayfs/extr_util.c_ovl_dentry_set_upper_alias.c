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
struct dentry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  OVL_E_UPPER_ALIAS ; 
 int /*<<< orphan*/  ovl_dentry_set_flag (int /*<<< orphan*/ ,struct dentry*) ; 

void ovl_dentry_set_upper_alias(struct dentry *dentry)
{
	ovl_dentry_set_flag(OVL_E_UPPER_ALIAS, dentry);
}