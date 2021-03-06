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
struct nouveau_vma {scalar_t__ node; } ;

/* Variables and functions */
 int /*<<< orphan*/  nouveau_vm_put (struct nouveau_vma*) ; 
 int /*<<< orphan*/  nouveau_vm_unmap (struct nouveau_vma*) ; 

void
nouveau_gpuobj_unmap(struct nouveau_vma *vma)
{
	if (vma->node) {
		nouveau_vm_unmap(vma);
		nouveau_vm_put(vma);
	}
}