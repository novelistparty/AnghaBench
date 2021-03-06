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
struct sn9c102_sensor {int dummy; } ;
struct sn9c102_device {int /*<<< orphan*/  sensor; } ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,struct sn9c102_sensor const*,int) ; 

void
sn9c102_attach_sensor(struct sn9c102_device* cam,
		      const struct sn9c102_sensor* sensor)
{
	memcpy(&cam->sensor, sensor, sizeof(struct sn9c102_sensor));
}