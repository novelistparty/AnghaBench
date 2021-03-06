#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct thermal_zone_device {struct __thermal_zone* devdata; } ;
struct __thermal_zone {int ntrips; TYPE_1__* trips; } ;
struct TYPE_2__ {scalar_t__ type; int temperature; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ THERMAL_TRIP_CRITICAL ; 

__attribute__((used)) static int of_thermal_get_crit_temp(struct thermal_zone_device *tz,
				    int *temp)
{
	struct __thermal_zone *data = tz->devdata;
	int i;

	for (i = 0; i < data->ntrips; i++)
		if (data->trips[i].type == THERMAL_TRIP_CRITICAL) {
			*temp = data->trips[i].temperature;
			return 0;
		}

	return -EINVAL;
}