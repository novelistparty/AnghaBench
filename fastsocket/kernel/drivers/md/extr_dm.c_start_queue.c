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
struct request_queue {int /*<<< orphan*/  queue_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __start_queue (struct request_queue*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 

__attribute__((used)) static void start_queue(struct request_queue *q)
{
	unsigned long flags;

	spin_lock_irqsave(q->queue_lock, flags);
	__start_queue(q);
	spin_unlock_irqrestore(q->queue_lock, flags);
}