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
struct xgbe_prv_data {int dummy; } ;

/* Variables and functions */
 int __xgbe_phy_config_aneg (struct xgbe_prv_data*,int) ; 

__attribute__((used)) static int xgbe_phy_reconfig_aneg(struct xgbe_prv_data *pdata)
{
	return __xgbe_phy_config_aneg(pdata, false);
}