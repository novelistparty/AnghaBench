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

/* Variables and functions */
 int /*<<< orphan*/  BTC_MAIN_INIT_FUTURE ; 
 int /*<<< orphan*/  FUTURE_SUCCESS ; 
 int /*<<< orphan*/ * btc_main_get_future_p (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  future_ready (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void btc_init_callback(void)
{
    future_ready(*btc_main_get_future_p(BTC_MAIN_INIT_FUTURE), FUTURE_SUCCESS);
}