#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zdev_t ;
typedef  int /*<<< orphan*/  u8_t ;
struct TYPE_3__ {scalar_t__ bChannelScan; } ;
struct TYPE_4__ {TYPE_1__ sta; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 TYPE_2__* wd ; 
 int /*<<< orphan*/  zmw_get_wlan_dev (int /*<<< orphan*/ *) ; 

u8_t zfStaBlockWlanScan(zdev_t* dev)
{
    u8_t   ret=FALSE;

    zmw_get_wlan_dev(dev);

    if ( wd->sta.bChannelScan )
    {
        return TRUE;
    }

    return ret;
}