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
typedef  int /*<<< orphan*/  fz_scale_filter ;

/* Variables and functions */

__attribute__((used)) static float
simple(fz_scale_filter *filter, float x)
{
	if (x >= 1)
		return 0;
	return 1 + (2*x - 3)*x*x;
}