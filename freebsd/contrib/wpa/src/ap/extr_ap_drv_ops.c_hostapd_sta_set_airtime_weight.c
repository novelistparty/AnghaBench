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
typedef  int /*<<< orphan*/  u8 ;
struct hostapd_data {int /*<<< orphan*/  drv_priv; TYPE_1__* driver; } ;
struct TYPE_2__ {int (* sta_set_airtime_weight ) (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,unsigned int) ;} ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,unsigned int) ; 

int hostapd_sta_set_airtime_weight(struct hostapd_data *hapd, const u8 *addr,
				   unsigned int weight)
{
	if (!hapd->driver || !hapd->driver->sta_set_airtime_weight)
		return 0;
	return hapd->driver->sta_set_airtime_weight(hapd->drv_priv, addr,
						    weight);
}