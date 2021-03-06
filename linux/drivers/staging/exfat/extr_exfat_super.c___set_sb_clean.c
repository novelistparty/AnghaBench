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
struct exfat_sb_info {scalar_t__ s_dirt; } ;

/* Variables and functions */
 struct exfat_sb_info* EXFAT_SB (struct super_block*) ; 

__attribute__((used)) static void __set_sb_clean(struct super_block *sb)
{
	struct exfat_sb_info *sbi = EXFAT_SB(sb);

	sbi->s_dirt = 0;
}