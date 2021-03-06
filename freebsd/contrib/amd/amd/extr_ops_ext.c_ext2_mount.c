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
typedef  int /*<<< orphan*/  mntfs ;
typedef  int /*<<< orphan*/  am_node ;

/* Variables and functions */
 int /*<<< orphan*/  MNTTAB_TYPE_EXT2 ; 
 int /*<<< orphan*/  MOUNT_TYPE_EXT2 ; 
 int ext_mount (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ext2_mount(am_node *am, mntfs *mf)
{
  return ext_mount(am, mf, MOUNT_TYPE_EXT2, MNTTAB_TYPE_EXT2);
}