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
struct net_device {scalar_t__ addr_len; scalar_t__ dev_addr; } ;

/* Variables and functions */
 scalar_t__ ARCNET_ALEN ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int addrconf_ifid_arcnet(u8 *eui, struct net_device *dev)
{
	/* XXX: inherit EUI-64 from other interface -- yoshfuji */
	if (dev->addr_len != ARCNET_ALEN)
		return -1;
	memset(eui, 0, 7);
	eui[7] = *(u8*)dev->dev_addr;
	return 0;
}