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
 int /*<<< orphan*/  dev_attr_pec ; 
 int /*<<< orphan*/  device_remove_file (void*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void lm90_remove_pec(void *dev)
{
	device_remove_file(dev, &dev_attr_pec);
}