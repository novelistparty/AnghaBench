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
struct hostapd_data {int /*<<< orphan*/  drv_priv; TYPE_1__* driver; } ;
struct TYPE_2__ {int (* set_frag ) (int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ ,int) ; 

int hostapd_set_frag(struct hostapd_data *hapd, int frag)
{
	if (hapd->driver == NULL || hapd->driver->set_frag == NULL)
		return 0;
	return hapd->driver->set_frag(hapd->drv_priv, frag);
}