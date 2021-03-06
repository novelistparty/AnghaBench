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
struct sysv_sb_info {scalar_t__ s_type; scalar_t__* s_sb_state; int /*<<< orphan*/  s_bh2; scalar_t__* s_sb_time; } ;
struct super_block {int dummy; } ;

/* Variables and functions */
 scalar_t__ FSTYPE_SYSV4 ; 
 struct sysv_sb_info* SYSV_SB (struct super_block*) ; 
 scalar_t__ cpu_to_fs32 (struct sysv_sb_info*,unsigned long) ; 
 unsigned long fs32_to_cpu (struct sysv_sb_info*,scalar_t__) ; 
 unsigned long get_seconds () ; 
 int /*<<< orphan*/  lock_super (struct super_block*) ; 
 int /*<<< orphan*/  mark_buffer_dirty (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  unlock_super (struct super_block*) ; 

__attribute__((used)) static int sysv_sync_fs(struct super_block *sb, int wait)
{
	struct sysv_sb_info *sbi = SYSV_SB(sb);
	unsigned long time = get_seconds(), old_time;

	lock_super(sb);

	/*
	 * If we are going to write out the super block,
	 * then attach current time stamp.
	 * But if the filesystem was marked clean, keep it clean.
	 */
	old_time = fs32_to_cpu(sbi, *sbi->s_sb_time);
	if (sbi->s_type == FSTYPE_SYSV4) {
		if (*sbi->s_sb_state == cpu_to_fs32(sbi, 0x7c269d38 - old_time))
			*sbi->s_sb_state = cpu_to_fs32(sbi, 0x7c269d38 - time);
		*sbi->s_sb_time = cpu_to_fs32(sbi, time);
		mark_buffer_dirty(sbi->s_bh2);
	}

	unlock_super(sb);

	return 0;
}