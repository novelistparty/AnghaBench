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
struct proc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  aio_job_mtx ; 
 scalar_t__ aio_kick (struct proc*) ; 
 int /*<<< orphan*/  mtx_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mtx_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
aio_kick_helper(void *context, int pending)
{
	struct proc *userp = context;

	mtx_lock(&aio_job_mtx);
	while (--pending >= 0) {
		if (aio_kick(userp))
			break;
	}
	mtx_unlock(&aio_job_mtx);
}