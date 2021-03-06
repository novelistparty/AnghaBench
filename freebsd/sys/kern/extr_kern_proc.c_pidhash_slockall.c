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
typedef  size_t u_long ;

/* Variables and functions */
 size_t pidhashlock ; 
 int /*<<< orphan*/ * pidhashtbl_lock ; 
 int /*<<< orphan*/  sx_slock (int /*<<< orphan*/ *) ; 

void
pidhash_slockall(void)
{
	u_long i;

	for (i = 0; i < pidhashlock + 1; i++)
		sx_slock(&pidhashtbl_lock[i]);
}