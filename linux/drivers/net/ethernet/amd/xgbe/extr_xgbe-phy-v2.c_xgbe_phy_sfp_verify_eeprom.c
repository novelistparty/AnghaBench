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
typedef  scalar_t__ u8 ;

/* Variables and functions */

__attribute__((used)) static bool xgbe_phy_sfp_verify_eeprom(u8 cc_in, u8 *buf, unsigned int len)
{
	u8 cc;

	for (cc = 0; len; buf++, len--)
		cc += *buf;

	return (cc == cc_in) ? true : false;
}