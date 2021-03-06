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
struct task_struct {scalar_t__ policy; } ;
struct sched_rt_entity {int dummy; } ;
struct rt_rq {unsigned int rr_nr_running; } ;

/* Variables and functions */
 scalar_t__ SCHED_RR ; 
 struct rt_rq* group_rt_rq (struct sched_rt_entity*) ; 
 struct task_struct* rt_task_of (struct sched_rt_entity*) ; 

__attribute__((used)) static inline
unsigned int rt_se_rr_nr_running(struct sched_rt_entity *rt_se)
{
	struct rt_rq *group_rq = group_rt_rq(rt_se);
	struct task_struct *tsk;

	if (group_rq)
		return group_rq->rr_nr_running;

	tsk = rt_task_of(rt_se);

	return (tsk->policy == SCHED_RR) ? 1 : 0;
}