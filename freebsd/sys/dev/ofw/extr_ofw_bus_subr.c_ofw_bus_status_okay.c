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
typedef  int /*<<< orphan*/  device_t ;

/* Variables and functions */
 char* ofw_bus_get_status (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char const*,char*) ; 

int
ofw_bus_status_okay(device_t dev)
{
	const char *status;

	status = ofw_bus_get_status(dev);
	if (status == NULL || strcmp(status, "okay") == 0 ||
	    strcmp(status, "ok") == 0)
		return (1);
	
	return (0);
}