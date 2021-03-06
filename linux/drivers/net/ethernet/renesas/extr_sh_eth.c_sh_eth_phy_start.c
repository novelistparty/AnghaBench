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
struct net_device {int /*<<< orphan*/  phydev; } ;

/* Variables and functions */
 int /*<<< orphan*/  phy_start (int /*<<< orphan*/ ) ; 
 int sh_eth_phy_init (struct net_device*) ; 

__attribute__((used)) static int sh_eth_phy_start(struct net_device *ndev)
{
	int ret;

	ret = sh_eth_phy_init(ndev);
	if (ret)
		return ret;

	phy_start(ndev->phydev);

	return 0;
}