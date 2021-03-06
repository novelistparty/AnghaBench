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
typedef  scalar_t__ vm_paddr_t ;
typedef  scalar_t__ vm_ooffset_t ;
typedef  int /*<<< orphan*/  vm_memattr_t ;
typedef  int /*<<< orphan*/  uint8_t ;
struct fb_info {int fb_flags; scalar_t__ fb_size; scalar_t__ fb_pbase; int /*<<< orphan*/  fb_memattr; scalar_t__ fb_vbase; } ;
struct cdev {struct fb_info* si_drv1; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int FB_FLAG_MEMATTR ; 
 int FB_FLAG_NOMMAP ; 
 scalar_t__ vtophys (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
fb_mmap(struct cdev *dev, vm_ooffset_t offset, vm_paddr_t *paddr, int nprot,
    vm_memattr_t *memattr)
{
	struct fb_info *info;

	info = dev->si_drv1;

	if (info->fb_flags & FB_FLAG_NOMMAP)
		return (ENODEV);

	if (offset >= 0 && offset < info->fb_size) {
		if (info->fb_pbase == 0)
			*paddr = vtophys((uint8_t *)info->fb_vbase + offset);
		else
			*paddr = info->fb_pbase + offset;
		if (info->fb_flags & FB_FLAG_MEMATTR)
			*memattr = info->fb_memattr;
		return (0);
	}
	return (EINVAL);
}