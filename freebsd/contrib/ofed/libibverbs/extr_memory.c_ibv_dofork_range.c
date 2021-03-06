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

/* Variables and functions */
 int /*<<< orphan*/  MADV_DOFORK ; 
 int ibv_madvise_range (void*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ mm_root ; 
 int too_late ; 

int ibv_dofork_range(void *base, size_t size)
{
	if (mm_root)
		return ibv_madvise_range(base, size, MADV_DOFORK);
	else {
		too_late = 1;
		return 0;
	}
}