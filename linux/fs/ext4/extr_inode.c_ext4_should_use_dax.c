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
struct inode {int /*<<< orphan*/  i_mode; int /*<<< orphan*/  i_sb; } ;

/* Variables and functions */
 int /*<<< orphan*/  DAX ; 
 int /*<<< orphan*/  EXT4_INODE_ENCRYPT ; 
 int /*<<< orphan*/  EXT4_INODE_VERITY ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 scalar_t__ ext4_has_inline_data (struct inode*) ; 
 scalar_t__ ext4_should_journal_data (struct inode*) ; 
 scalar_t__ ext4_test_inode_flag (struct inode*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  test_opt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool ext4_should_use_dax(struct inode *inode)
{
	if (!test_opt(inode->i_sb, DAX))
		return false;
	if (!S_ISREG(inode->i_mode))
		return false;
	if (ext4_should_journal_data(inode))
		return false;
	if (ext4_has_inline_data(inode))
		return false;
	if (ext4_test_inode_flag(inode, EXT4_INODE_ENCRYPT))
		return false;
	if (ext4_test_inode_flag(inode, EXT4_INODE_VERITY))
		return false;
	return true;
}