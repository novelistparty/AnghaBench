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
struct device {int dummy; } ;

/* Variables and functions */
 unsigned int CS53L30_IS ; 

__attribute__((used)) static bool cs53l30_volatile_register(struct device *dev, unsigned int reg)
{
	if (reg == CS53L30_IS)
		return true;
	else
		return false;
}