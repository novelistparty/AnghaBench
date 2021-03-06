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

/* Variables and functions */
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int /*<<< orphan*/ * debugfs_create_dir (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * root_folder ; 

void brcms_debugfs_init(void)
{
	root_folder = debugfs_create_dir(KBUILD_MODNAME, NULL);
	if (IS_ERR(root_folder))
		root_folder = NULL;
}