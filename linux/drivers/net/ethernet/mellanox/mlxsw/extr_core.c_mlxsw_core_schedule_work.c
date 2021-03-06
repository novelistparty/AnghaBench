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
struct work_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_owq ; 
 int queue_work (int /*<<< orphan*/ ,struct work_struct*) ; 

bool mlxsw_core_schedule_work(struct work_struct *work)
{
	return queue_work(mlxsw_owq, work);
}