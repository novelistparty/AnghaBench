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
struct rtw_dev {struct rtw_chip_info* chip; } ;
struct rtw_chip_info {TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* false_alarm_statistics ) (struct rtw_dev*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct rtw_dev*) ; 

__attribute__((used)) static void rtw_phy_stat_false_alarm(struct rtw_dev *rtwdev)
{
	struct rtw_chip_info *chip = rtwdev->chip;

	chip->ops->false_alarm_statistics(rtwdev);
}