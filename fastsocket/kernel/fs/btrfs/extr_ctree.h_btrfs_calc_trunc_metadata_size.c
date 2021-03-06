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
typedef  int u64 ;
struct btrfs_root {int leafsize; int nodesize; } ;

/* Variables and functions */
 int BTRFS_MAX_LEVEL ; 

__attribute__((used)) static inline u64 btrfs_calc_trunc_metadata_size(struct btrfs_root *root,
						 unsigned num_items)
{
	return (root->leafsize + root->nodesize * (BTRFS_MAX_LEVEL - 1)) *
		num_items;
}