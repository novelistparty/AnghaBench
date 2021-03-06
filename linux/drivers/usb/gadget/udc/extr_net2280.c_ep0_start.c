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
struct net2280 {int quirks; } ;

/* Variables and functions */
 int PLX_LEGACY ; 
 void ep0_start_228x (struct net2280*) ; 
 void ep0_start_338x (struct net2280*) ; 

__attribute__((used)) static void ep0_start(struct net2280 *dev)
{
	if (dev->quirks & PLX_LEGACY)
		return ep0_start_228x(dev);
	return ep0_start_338x(dev);
}