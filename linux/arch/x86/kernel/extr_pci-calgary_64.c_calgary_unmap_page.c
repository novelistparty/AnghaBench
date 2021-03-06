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
struct iommu_table {int dummy; } ;
struct device {int dummy; } ;
typedef  enum dma_data_direction { ____Placeholder_dma_data_direction } dma_data_direction ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct iommu_table* find_iommu_table (struct device*) ; 
 int /*<<< orphan*/  iommu_free (struct iommu_table*,int /*<<< orphan*/ ,unsigned int) ; 
 unsigned int iommu_num_pages (int /*<<< orphan*/ ,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void calgary_unmap_page(struct device *dev, dma_addr_t dma_addr,
			       size_t size, enum dma_data_direction dir,
			       unsigned long attrs)
{
	struct iommu_table *tbl = find_iommu_table(dev);
	unsigned int npages;

	npages = iommu_num_pages(dma_addr, size, PAGE_SIZE);
	iommu_free(tbl, dma_addr, npages);
}