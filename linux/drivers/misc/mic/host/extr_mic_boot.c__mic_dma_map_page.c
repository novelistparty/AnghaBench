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
struct page {int dummy; } ;
struct mic_device {int dummy; } ;
struct device {int dummy; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  mic_map_single (struct mic_device*,void*,size_t) ; 
 int /*<<< orphan*/  page_to_phys (struct page*) ; 
 void* phys_to_virt (int /*<<< orphan*/ ) ; 
 struct mic_device* vpdev_to_mdev (struct device*) ; 

__attribute__((used)) static dma_addr_t
_mic_dma_map_page(struct device *dev, struct page *page,
		  unsigned long offset, size_t size,
		  enum dma_data_direction dir, unsigned long attrs)
{
	void *va = phys_to_virt(page_to_phys(page)) + offset;
	struct mic_device *mdev = vpdev_to_mdev(dev);

	return mic_map_single(mdev, va, size);
}