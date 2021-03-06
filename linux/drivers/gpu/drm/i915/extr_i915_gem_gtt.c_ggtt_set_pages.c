#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct i915_vma {TYPE_2__* obj; int /*<<< orphan*/  page_sizes; int /*<<< orphan*/  pages; } ;
struct TYPE_3__ {int /*<<< orphan*/  page_sizes; } ;
struct TYPE_4__ {TYPE_1__ mm; } ;

/* Variables and functions */
 int /*<<< orphan*/  GEM_BUG_ON (int /*<<< orphan*/ ) ; 
 int i915_get_ggtt_vma_pages (struct i915_vma*) ; 

__attribute__((used)) static int ggtt_set_pages(struct i915_vma *vma)
{
	int ret;

	GEM_BUG_ON(vma->pages);

	ret = i915_get_ggtt_vma_pages(vma);
	if (ret)
		return ret;

	vma->page_sizes = vma->obj->mm.page_sizes;

	return 0;
}