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
 size_t FX_RELEASE ; 
 int* xg_sense ; 

__attribute__((used)) static int xg_release(int val)
{
	return -(val - 64) * xg_sense[FX_RELEASE] / 64;
}