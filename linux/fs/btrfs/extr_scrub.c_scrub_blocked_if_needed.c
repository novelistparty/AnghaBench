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
struct btrfs_fs_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  scrub_pause_off (struct btrfs_fs_info*) ; 
 int /*<<< orphan*/  scrub_pause_on (struct btrfs_fs_info*) ; 

__attribute__((used)) static void scrub_blocked_if_needed(struct btrfs_fs_info *fs_info)
{
	scrub_pause_on(fs_info);
	scrub_pause_off(fs_info);
}