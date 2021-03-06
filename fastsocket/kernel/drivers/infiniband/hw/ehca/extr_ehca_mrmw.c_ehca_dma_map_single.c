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
typedef  int /*<<< orphan*/  u64 ;
struct ib_device {int dummy; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;

/* Variables and functions */
 int /*<<< orphan*/  EHCA_INVAL_ADDR ; 
 int /*<<< orphan*/  ehca_map_vaddr (void*) ; 

__attribute__((used)) static u64 ehca_dma_map_single(struct ib_device *dev, void *cpu_addr,
			       size_t size, enum dma_data_direction direction)
{
	if (cpu_addr)
		return ehca_map_vaddr(cpu_addr);
	else
		return EHCA_INVAL_ADDR;
}