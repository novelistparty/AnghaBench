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
typedef  int /*<<< orphan*/  tBTA_START_STOP_ADV_CMPL_CBACK ;

/* Variables and functions */
 int /*<<< orphan*/  BTA_DmBleBroadcast (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void btc_ble_stop_advertising(tBTA_START_STOP_ADV_CMPL_CBACK *stop_adv_cb)
{
    bool stop_adv = false;

    BTA_DmBleBroadcast(stop_adv, stop_adv_cb);
}