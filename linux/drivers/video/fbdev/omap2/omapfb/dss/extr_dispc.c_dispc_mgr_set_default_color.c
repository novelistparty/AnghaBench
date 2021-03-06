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
typedef  int /*<<< orphan*/  u32 ;
typedef  enum omap_channel { ____Placeholder_omap_channel } omap_channel ;

/* Variables and functions */
 int /*<<< orphan*/  DISPC_DEFAULT_COLOR (int) ; 
 int /*<<< orphan*/  dispc_write_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void dispc_mgr_set_default_color(enum omap_channel channel, u32 color)
{
	dispc_write_reg(DISPC_DEFAULT_COLOR(channel), color);
}