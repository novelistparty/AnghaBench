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
struct inode {int dummy; } ;
struct buffer_head {int dummy; } ;
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int nilfs_mdt_get_block (struct inode*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,struct buffer_head**) ; 
 int /*<<< orphan*/  nilfs_palloc_entry_blkoff (struct inode*,int /*<<< orphan*/ ) ; 

int nilfs_palloc_get_entry_block(struct inode *inode, __u64 nr,
				 int create, struct buffer_head **bhp)
{
	return nilfs_mdt_get_block(inode, nilfs_palloc_entry_blkoff(inode, nr),
				   create, NULL, bhp);
}