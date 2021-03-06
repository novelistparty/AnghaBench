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
struct buffer_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  REQ_SYNC ; 
 int __sync_dirty_buffer (struct buffer_head*,int /*<<< orphan*/ ) ; 

int sync_dirty_buffer(struct buffer_head *bh)
{
	return __sync_dirty_buffer(bh, REQ_SYNC);
}