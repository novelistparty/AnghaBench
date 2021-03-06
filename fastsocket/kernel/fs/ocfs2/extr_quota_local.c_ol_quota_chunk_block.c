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

/* Variables and functions */
 int ol_chunk_blocks (struct super_block*) ; 

__attribute__((used)) static unsigned int ol_quota_chunk_block(struct super_block *sb, int c)
{
	/* 1 block for local quota file info, 1 block per chunk for chunk info */
	return 1 + (ol_chunk_blocks(sb) + 1) * c;
}