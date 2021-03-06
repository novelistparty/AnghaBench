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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_4__ {TYPE_1__* ops; } ;
struct rtw_dev {TYPE_2__ hci; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* read32 ) (struct rtw_dev*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct rtw_dev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 rtw_read32(struct rtw_dev *rtwdev, u32 addr)
{
	return rtwdev->hci.ops->read32(rtwdev, addr);
}