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
 int /*<<< orphan*/  SPRN_BESCR ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  mtspr (int /*<<< orphan*/ ,int) ; 

void ebb_global_enable(void)
{
	/* Enable EBBs globally and PMU EBBs */
	mtspr(SPRN_BESCR, 0x8000000100000000ull);
	mb();
}