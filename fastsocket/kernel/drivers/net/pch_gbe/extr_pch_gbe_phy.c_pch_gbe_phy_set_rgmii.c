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
struct pch_gbe_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pch_gbe_phy_sw_reset (struct pch_gbe_hw*) ; 

inline void pch_gbe_phy_set_rgmii(struct pch_gbe_hw *hw)
{
	pch_gbe_phy_sw_reset(hw);
}