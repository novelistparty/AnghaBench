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
 int /*<<< orphan*/  PINID_SSP1_CMD ; 
 int /*<<< orphan*/  stmp3xxx_pin_pullup (int /*<<< orphan*/ ,int,char*) ; 

__attribute__((used)) static void stmp3xxxmmc_cmd_pullup_ssp1(int enable)
{
	stmp3xxx_pin_pullup(PINID_SSP1_CMD, enable, "mmc");
}