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
struct srcu_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __synchronize_srcu (struct srcu_struct*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  synchronize_sched ; 

void synchronize_srcu(struct srcu_struct *sp)
{
	__synchronize_srcu(sp, synchronize_sched);
}