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
struct nvkm_therm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv50_sensor_setup (struct nvkm_therm*) ; 

__attribute__((used)) static void
nv50_therm_init(struct nvkm_therm *therm)
{
	nv50_sensor_setup(therm);
}