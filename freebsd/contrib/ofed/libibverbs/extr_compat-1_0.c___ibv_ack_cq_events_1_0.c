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
struct ibv_cq_1_0 {int /*<<< orphan*/  real_cq; } ;

/* Variables and functions */
 int /*<<< orphan*/  ibv_ack_cq_events (int /*<<< orphan*/ ,unsigned int) ; 

void __ibv_ack_cq_events_1_0(struct ibv_cq_1_0 *cq, unsigned int nevents)
{
	ibv_ack_cq_events(cq->real_cq, nevents);
}