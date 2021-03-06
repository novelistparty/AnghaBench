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
 int /*<<< orphan*/  DSS_CONTROL ; 
 int EINVAL ; 
#define  OMAP_DSS_CHANNEL_DIGIT 129 
#define  OMAP_DSS_CHANNEL_LCD2 128 
 int /*<<< orphan*/  REG_FLD_MOD (int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static int dss_dpi_select_source_omap4(int port, enum omap_channel channel)
{
	int val;

	switch (channel) {
	case OMAP_DSS_CHANNEL_LCD2:
		val = 0;
		break;
	case OMAP_DSS_CHANNEL_DIGIT:
		val = 1;
		break;
	default:
		return -EINVAL;
	}

	REG_FLD_MOD(DSS_CONTROL, val, 17, 17);

	return 0;
}