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
struct btc_bt_link_info {scalar_t__ pan_exist; scalar_t__ hid_exist; scalar_t__ a2dp_exist; scalar_t__ hid_only; scalar_t__ sco_exist; } ;
struct btc_coexist {int /*<<< orphan*/  (* btc_set ) (struct btc_coexist*,int /*<<< orphan*/ ,int*) ;int /*<<< orphan*/  (* btc_get ) (struct btc_coexist*,int /*<<< orphan*/ ,int*) ;struct btc_bt_link_info bt_link_info; } ;
struct TYPE_2__ {int /*<<< orphan*/  wifi_is_high_pri_task; } ;

/* Variables and functions */
 int /*<<< orphan*/  BTC_GET_BL_WIFI_AP_MODE_ENABLE ; 
 int /*<<< orphan*/  BTC_GET_BL_WIFI_BUSY ; 
 int /*<<< orphan*/  BTC_GET_BL_WIFI_CONNECTED ; 
 int /*<<< orphan*/  BTC_PS_WIFI_NATIVE ; 
 int /*<<< orphan*/  BTC_SET_BL_BT_TRAFFIC_BUSY ; 
 int /*<<< orphan*/  NORMAL_EXEC ; 
 int /*<<< orphan*/  btc8821a1ant_coex_table_with_type (struct btc_coexist*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  btc8821a1ant_power_save_state (struct btc_coexist*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  btc8821a1ant_ps_tdma (struct btc_coexist*,int /*<<< orphan*/ ,int,int) ; 
 TYPE_1__* coex_sta ; 
 int /*<<< orphan*/  stub1 (struct btc_coexist*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  stub2 (struct btc_coexist*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  stub3 (struct btc_coexist*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  stub4 (struct btc_coexist*,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static void btc8821a1ant_action_bt_inquiry(struct btc_coexist *btcoexist)
{
	struct btc_bt_link_info *bt_link_info = &btcoexist->bt_link_info;
	bool wifi_connected = false;
	bool ap_enable = false;
	bool wifi_busy = false, bt_busy = false;

	btcoexist->btc_get(btcoexist, BTC_GET_BL_WIFI_CONNECTED,
			   &wifi_connected);
	btcoexist->btc_get(btcoexist, BTC_GET_BL_WIFI_AP_MODE_ENABLE,
			   &ap_enable);
	btcoexist->btc_get(btcoexist, BTC_GET_BL_WIFI_BUSY, &wifi_busy);
	btcoexist->btc_set(btcoexist, BTC_SET_BL_BT_TRAFFIC_BUSY, &bt_busy);

	if (!wifi_connected && !coex_sta->wifi_is_high_pri_task) {
		btc8821a1ant_power_save_state(btcoexist,
					      BTC_PS_WIFI_NATIVE, 0x0, 0x0);
		btc8821a1ant_ps_tdma(btcoexist, NORMAL_EXEC, false, 8);
		btc8821a1ant_coex_table_with_type(btcoexist, NORMAL_EXEC, 0);
	} else if ((bt_link_info->sco_exist) || (bt_link_info->a2dp_exist) ||
		   (bt_link_info->hid_only)) {
		/* SCO/HID-only busy */
		btc8821a1ant_power_save_state(btcoexist,
					      BTC_PS_WIFI_NATIVE, 0x0, 0x0);
		btc8821a1ant_ps_tdma(btcoexist, NORMAL_EXEC, true, 32);
		btc8821a1ant_coex_table_with_type(btcoexist, NORMAL_EXEC, 4);
	} else if ((bt_link_info->a2dp_exist) && (bt_link_info->hid_exist)) {
		/* A2DP+HID busy */
		btc8821a1ant_power_save_state(btcoexist, BTC_PS_WIFI_NATIVE,
					      0x0, 0x0);
		btc8821a1ant_ps_tdma(btcoexist, NORMAL_EXEC, true, 14);

		btc8821a1ant_coex_table_with_type(btcoexist, NORMAL_EXEC, 1);
	} else if ((bt_link_info->pan_exist) || (wifi_busy)) {
		btc8821a1ant_power_save_state(btcoexist, BTC_PS_WIFI_NATIVE,
					      0x0, 0x0);
		btc8821a1ant_ps_tdma(btcoexist, NORMAL_EXEC, true, 20);

		btc8821a1ant_coex_table_with_type(btcoexist, NORMAL_EXEC, 4);
	} else {
		btc8821a1ant_power_save_state(btcoexist, BTC_PS_WIFI_NATIVE,
					      0x0, 0x0);
		btc8821a1ant_ps_tdma(btcoexist, NORMAL_EXEC, false, 8);
		btc8821a1ant_coex_table_with_type(btcoexist, NORMAL_EXEC, 7);
	}
}