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
struct rcu_state {int dummy; } ;
struct rcu_data {scalar_t__** nxttail; } ;

/* Variables and functions */
 size_t RCU_DONE_TAIL ; 
 int /*<<< orphan*/  rcu_gp_in_progress (struct rcu_state*) ; 

__attribute__((used)) static int
cpu_needs_another_gp(struct rcu_state *rsp, struct rcu_data *rdp)
{
	return *rdp->nxttail[RCU_DONE_TAIL] && !rcu_gp_in_progress(rsp);
}