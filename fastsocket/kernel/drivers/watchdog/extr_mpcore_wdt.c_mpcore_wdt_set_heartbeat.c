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
 int EINVAL ; 
 int mpcore_margin ; 

__attribute__((used)) static int mpcore_wdt_set_heartbeat(int t)
{
	if (t < 0x0001 || t > 0xFFFF)
		return -EINVAL;

	mpcore_margin = t;
	return 0;
}