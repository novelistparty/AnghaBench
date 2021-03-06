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
struct super_block {int dummy; } ;
struct inode {int i_mode; int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_mtime; int /*<<< orphan*/  i_atime; int /*<<< orphan*/  i_ino; } ;

/* Variables and functions */
 scalar_t__ BINDERFS_MAX_MINOR ; 
 scalar_t__ INODE_OFFSET ; 
 int /*<<< orphan*/  current_time (struct inode*) ; 
 int /*<<< orphan*/  iunique (struct super_block*,scalar_t__) ; 
 struct inode* new_inode (struct super_block*) ; 

__attribute__((used)) static struct inode *binderfs_make_inode(struct super_block *sb, int mode)
{
	struct inode *ret;

	ret = new_inode(sb);
	if (ret) {
		ret->i_ino = iunique(sb, BINDERFS_MAX_MINOR + INODE_OFFSET);
		ret->i_mode = mode;
		ret->i_atime = ret->i_mtime = ret->i_ctime = current_time(ret);
	}
	return ret;
}