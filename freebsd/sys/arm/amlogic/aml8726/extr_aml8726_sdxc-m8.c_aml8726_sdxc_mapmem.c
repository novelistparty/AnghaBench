#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  ds_addr; } ;
typedef  TYPE_1__ bus_dma_segment_t ;
typedef  int /*<<< orphan*/  bus_addr_t ;

/* Variables and functions */

__attribute__((used)) static void
aml8726_sdxc_mapmem(void *arg, bus_dma_segment_t *segs, int nseg, int error)
{
	bus_addr_t *busaddrp;

	/*
	 * There should only be one bus space address since
	 * bus_dma_tag_create was called with nsegments = 1.
	 */

	 busaddrp = (bus_addr_t *)arg;
	 *busaddrp = segs->ds_addr;
}