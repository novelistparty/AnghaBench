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
struct phy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PHYCTRL_PDB_PWR_OFF ; 
 int rockchip_emmc_phy_power (struct phy*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rockchip_emmc_phy_power_off(struct phy *phy)
{
	/* Power down emmc phy analog blocks */
	return rockchip_emmc_phy_power(phy, PHYCTRL_PDB_PWR_OFF);
}