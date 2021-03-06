#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct inode {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  cache_validity; } ;

/* Variables and functions */
 TYPE_1__* NFS_I (struct inode*) ; 
 int /*<<< orphan*/  NFS_INO_INVALID_OTHER ; 
 int /*<<< orphan*/  inc_nlink (struct inode*) ; 

__attribute__((used)) static void
nfs4_inc_nlink_locked(struct inode *inode)
{
	NFS_I(inode)->cache_validity |= NFS_INO_INVALID_OTHER;
	inc_nlink(inode);
}