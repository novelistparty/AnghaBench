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
typedef  int /*<<< orphan*/  platform_t ;

/* Variables and functions */
 int /*<<< orphan*/  ofw_cpu_early_foreach (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  virt_start_ap ; 

void
virt_mp_start_ap(platform_t plat)
{

	ofw_cpu_early_foreach(virt_start_ap, true);
}