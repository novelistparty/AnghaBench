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
typedef  int /*<<< orphan*/  u8 ;
struct dw_hdmi {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  HDMI_PHY_CONF0 ; 
 int /*<<< orphan*/  HDMI_PHY_CONF0_GEN2_PDDQ_MASK ; 
 int /*<<< orphan*/  HDMI_PHY_CONF0_GEN2_PDDQ_OFFSET ; 
 int /*<<< orphan*/  hdmi_mask_writeb (struct dw_hdmi*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void dw_hdmi_phy_gen2_pddq(struct dw_hdmi *hdmi, u8 enable)
{
	hdmi_mask_writeb(hdmi, enable, HDMI_PHY_CONF0,
			 HDMI_PHY_CONF0_GEN2_PDDQ_OFFSET,
			 HDMI_PHY_CONF0_GEN2_PDDQ_MASK);
}