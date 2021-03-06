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
struct led_priv {int /*<<< orphan*/  sw_led; } ;
struct adapter {struct led_priv ledpriv; } ;

/* Variables and functions */
 int /*<<< orphan*/  DeInitLed871x (int /*<<< orphan*/ *) ; 

void rtw_hal_sw_led_deinit(struct adapter *padapter)
{
	struct led_priv *ledpriv = &padapter->ledpriv;

	DeInitLed871x(&ledpriv->sw_led);
}