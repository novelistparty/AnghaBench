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
struct net_device {int dummy; } ;
struct ethtool_wolinfo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  memset (struct ethtool_wolinfo*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pegasus_set_wol (struct net_device*,struct ethtool_wolinfo*) ; 

__attribute__((used)) static inline void pegasus_reset_wol(struct net_device *dev)
{
	struct ethtool_wolinfo wol;

	memset(&wol, 0, sizeof wol);
	(void) pegasus_set_wol(dev, &wol);
}