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
struct sta_info {int dummy; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  set_sta_rate (struct adapter*,struct sta_info*) ; 

__attribute__((used)) static void rtw_dm_ra_mask_hdl(struct adapter *padapter, struct sta_info *psta)
{
	if (psta) {
		set_sta_rate(padapter, psta);
	}
}