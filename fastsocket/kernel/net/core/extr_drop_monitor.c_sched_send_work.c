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
struct per_cpu_dm_data {int /*<<< orphan*/  dm_alert_work; } ;

/* Variables and functions */
 int /*<<< orphan*/  schedule_work (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void sched_send_work(unsigned long _data)
{
	struct per_cpu_dm_data *data = (struct per_cpu_dm_data *)_data;

	schedule_work(&data->dm_alert_work);
}