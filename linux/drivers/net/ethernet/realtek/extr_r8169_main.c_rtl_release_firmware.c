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
struct rtl8169_private {int /*<<< orphan*/ * rtl_fw; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rtl_fw_release_firmware (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void rtl_release_firmware(struct rtl8169_private *tp)
{
	if (tp->rtl_fw) {
		rtl_fw_release_firmware(tp->rtl_fw);
		kfree(tp->rtl_fw);
		tp->rtl_fw = NULL;
	}
}