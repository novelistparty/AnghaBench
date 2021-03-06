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
struct videobuf_dmabuf {int nr_pages; int /*<<< orphan*/  direction; scalar_t__ bus_addr; int /*<<< orphan*/ * vaddr; int /*<<< orphan*/ * pages; int /*<<< orphan*/  sglen; int /*<<< orphan*/  magic; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DMA_NONE ; 
 int /*<<< orphan*/  MAGIC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAGIC_DMABUF ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  page_cache_release (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfree (int /*<<< orphan*/ *) ; 

int videobuf_dma_free(struct videobuf_dmabuf *dma)
{
	int i;
	MAGIC_CHECK(dma->magic, MAGIC_DMABUF);
	BUG_ON(dma->sglen);

	if (dma->pages) {
		for (i = 0; i < dma->nr_pages; i++)
			page_cache_release(dma->pages[i]);
		kfree(dma->pages);
		dma->pages = NULL;
	}

	vfree(dma->vaddr);
	dma->vaddr = NULL;

	if (dma->bus_addr)
		dma->bus_addr = 0;
	dma->direction = DMA_NONE;

	return 0;
}