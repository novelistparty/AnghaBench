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
typedef  scalar_t__ u64 ;
typedef  scalar_t__ s64 ;

/* Variables and functions */

__attribute__((used)) static inline void ef4_update_diff_stat(u64 *stat, u64 diff)
{
	if ((s64)(diff - *stat) > 0)
		*stat = diff;
}