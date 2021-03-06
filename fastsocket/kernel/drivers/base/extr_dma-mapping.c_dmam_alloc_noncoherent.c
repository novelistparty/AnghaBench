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
struct dma_devres {size_t size; int /*<<< orphan*/  dma_handle; void* vaddr; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  devres_add (struct device*,struct dma_devres*) ; 
 struct dma_devres* devres_alloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devres_free (struct dma_devres*) ; 
 void* dma_alloc_noncoherent (struct device*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dmam_noncoherent_release ; 

void *dmam_alloc_noncoherent(struct device *dev, size_t size,
			     dma_addr_t *dma_handle, gfp_t gfp)
{
	struct dma_devres *dr;
	void *vaddr;

	dr = devres_alloc(dmam_noncoherent_release, sizeof(*dr), gfp);
	if (!dr)
		return NULL;

	vaddr = dma_alloc_noncoherent(dev, size, dma_handle, gfp);
	if (!vaddr) {
		devres_free(dr);
		return NULL;
	}

	dr->vaddr = vaddr;
	dr->dma_handle = *dma_handle;
	dr->size = size;

	devres_add(dev, dr);

	return vaddr;
}