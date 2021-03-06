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
struct dma_debug_entry {unsigned long size; int direction; scalar_t__ sg_call_ents; int /*<<< orphan*/  dev_addr; struct device* dev; int /*<<< orphan*/  type; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  check_sync (struct device*,struct dma_debug_entry*,int) ; 
 int /*<<< orphan*/  dma_debug_single ; 
 int /*<<< orphan*/  global_disable ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

void debug_dma_sync_single_range_for_device(struct device *dev,
					    dma_addr_t dma_handle,
					    unsigned long offset,
					    size_t size, int direction)
{
	struct dma_debug_entry ref;

	if (unlikely(global_disable))
		return;

	ref.type         = dma_debug_single;
	ref.dev          = dev;
	ref.dev_addr     = dma_handle;
	ref.size         = offset + size;
	ref.direction    = direction;
	ref.sg_call_ents = 0;

	check_sync(dev, &ref, false);
}