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
struct nvmem_device {int dummy; } ;
struct nvmem_cell {struct nvmem_device* nvmem; } ;

/* Variables and functions */
 int /*<<< orphan*/  __nvmem_device_put (struct nvmem_device*) ; 

void nvmem_cell_put(struct nvmem_cell *cell)
{
	struct nvmem_device *nvmem = cell->nvmem;

	__nvmem_device_put(nvmem);
}