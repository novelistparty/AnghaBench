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
struct nouveau_vmmgr {int dummy; } ;
struct nouveau_vm {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 

int
nv04_vm_create(struct nouveau_vmmgr *vmm, u64 offset, u64 length, u64 mmstart,
	       struct nouveau_vm **pvm)
{
	return -EINVAL;
}