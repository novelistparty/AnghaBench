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
struct acpi_power_meter_resource {int dummy; } ;
struct acpi_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 struct acpi_power_meter_resource* acpi_driver_data (struct acpi_device*) ; 
 int /*<<< orphan*/  free_capabilities (struct acpi_power_meter_resource*) ; 
 int /*<<< orphan*/  read_capabilities (struct acpi_power_meter_resource*) ; 

__attribute__((used)) static int acpi_power_meter_resume(struct acpi_device *device)
{
	struct acpi_power_meter_resource *resource;

	if (!device || !acpi_driver_data(device))
		return -EINVAL;

	resource = acpi_driver_data(device);
	free_capabilities(resource);
	read_capabilities(resource);

	return 0;
}