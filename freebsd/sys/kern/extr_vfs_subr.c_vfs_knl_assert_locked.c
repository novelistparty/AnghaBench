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
struct vnode {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_VOP_LOCKED (struct vnode*,char*) ; 

__attribute__((used)) static void
vfs_knl_assert_locked(void *arg)
{
#ifdef DEBUG_VFS_LOCKS
	struct vnode *vp = arg;

	ASSERT_VOP_LOCKED(vp, "vfs_knl_assert_locked");
#endif
}