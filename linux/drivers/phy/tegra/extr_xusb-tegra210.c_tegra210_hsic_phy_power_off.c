#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct tegra_xusb_padctl {int dummy; } ;
struct tegra_xusb_lane {unsigned int index; TYPE_1__* pad; } ;
struct tegra_xusb_hsic_pad {int /*<<< orphan*/  supply; } ;
struct phy {int dummy; } ;
struct TYPE_2__ {struct tegra_xusb_padctl* padctl; } ;

/* Variables and functions */
 int /*<<< orphan*/  XUSB_PADCTL_HSIC_PADX_CTL0 (unsigned int) ; 
 int /*<<< orphan*/  XUSB_PADCTL_HSIC_PADX_CTL1 (unsigned int) ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA0 ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA1 ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_STROBE ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA0 ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA1 ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_STROBE ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA0 ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA1 ; 
 int XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_STROBE ; 
 int padctl_readl (struct tegra_xusb_padctl*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  padctl_writel (struct tegra_xusb_padctl*,int,int /*<<< orphan*/ ) ; 
 struct tegra_xusb_lane* phy_get_drvdata (struct phy*) ; 
 int /*<<< orphan*/  regulator_disable (int /*<<< orphan*/ ) ; 
 struct tegra_xusb_hsic_pad* to_hsic_pad (TYPE_1__*) ; 

__attribute__((used)) static int tegra210_hsic_phy_power_off(struct phy *phy)
{
	struct tegra_xusb_lane *lane = phy_get_drvdata(phy);
	struct tegra_xusb_hsic_pad *pad = to_hsic_pad(lane->pad);
	struct tegra_xusb_padctl *padctl = lane->pad->padctl;
	unsigned int index = lane->index;
	u32 value;

	value = padctl_readl(padctl, XUSB_PADCTL_HSIC_PADX_CTL0(index));
	value |= XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA0 |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_DATA1 |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_RX_STROBE |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA0 |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_DATA1 |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_ZI_STROBE |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA0 |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_DATA1 |
		 XUSB_PADCTL_HSIC_PAD_CTL0_PD_TX_STROBE;
	padctl_writel(padctl, value, XUSB_PADCTL_HSIC_PADX_CTL1(index));

	regulator_disable(pad->supply);

	return 0;
}