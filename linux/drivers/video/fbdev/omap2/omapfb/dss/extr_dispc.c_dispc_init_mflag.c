#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_4__ {TYPE_1__* feat; } ;
struct TYPE_3__ {scalar_t__ has_writeback; } ;

/* Variables and functions */
 int /*<<< orphan*/  DISPC_GLOBAL_MFLAG_ATTRIBUTE ; 
 int OMAP_DSS_WB ; 
 TYPE_2__ dispc ; 
 int dispc_ovl_get_fifo_size (int) ; 
 int /*<<< orphan*/  dispc_ovl_set_mflag (int,int) ; 
 int /*<<< orphan*/  dispc_ovl_set_mflag_threshold (int,int,int) ; 
 int /*<<< orphan*/  dispc_write_reg (int /*<<< orphan*/ ,int) ; 
 int dss_feat_get_buffer_size_unit () ; 
 int dss_feat_get_num_ovls () ; 

__attribute__((used)) static void dispc_init_mflag(void)
{
	int i;

	/*
	 * HACK: NV12 color format and MFLAG seem to have problems working
	 * together: using two displays, and having an NV12 overlay on one of
	 * the displays will cause underflows/synclosts when MFLAG_CTRL=2.
	 * Changing MFLAG thresholds and PRELOAD to certain values seem to
	 * remove the errors, but there doesn't seem to be a clear logic on
	 * which values work and which not.
	 *
	 * As a work-around, set force MFLAG to always on.
	 */
	dispc_write_reg(DISPC_GLOBAL_MFLAG_ATTRIBUTE,
		(1 << 0) |	/* MFLAG_CTRL = force always on */
		(0 << 2));	/* MFLAG_START = disable */

	for (i = 0; i < dss_feat_get_num_ovls(); ++i) {
		u32 size = dispc_ovl_get_fifo_size(i);
		u32 unit = dss_feat_get_buffer_size_unit();
		u32 low, high;

		dispc_ovl_set_mflag(i, true);

		/*
		 * Simulation team suggests below thesholds:
		 * HT = fifosize * 5 / 8;
		 * LT = fifosize * 4 / 8;
		 */

		low = size * 4 / 8 / unit;
		high = size * 5 / 8 / unit;

		dispc_ovl_set_mflag_threshold(i, low, high);
	}

	if (dispc.feat->has_writeback) {
		u32 size = dispc_ovl_get_fifo_size(OMAP_DSS_WB);
		u32 unit = dss_feat_get_buffer_size_unit();
		u32 low, high;

		dispc_ovl_set_mflag(OMAP_DSS_WB, true);

		/*
		 * Simulation team suggests below thesholds:
		 * HT = fifosize * 5 / 8;
		 * LT = fifosize * 4 / 8;
		 */

		low = size * 4 / 8 / unit;
		high = size * 5 / 8 / unit;

		dispc_ovl_set_mflag_threshold(OMAP_DSS_WB, low, high);
	}
}