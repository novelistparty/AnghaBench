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
typedef  enum omap_channel { ____Placeholder_omap_channel } omap_channel ;

/* Variables and functions */
 int /*<<< orphan*/  DISPC_MGR_FLD_ENABLE ; 
 int /*<<< orphan*/  mgr_fld_read (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mgr_fld_write (int,int /*<<< orphan*/ ,int) ; 

void dispc_mgr_enable(enum omap_channel channel, bool enable)
{
	mgr_fld_write(channel, DISPC_MGR_FLD_ENABLE, enable);
	/* flush posted write */
	mgr_fld_read(channel, DISPC_MGR_FLD_ENABLE);
}