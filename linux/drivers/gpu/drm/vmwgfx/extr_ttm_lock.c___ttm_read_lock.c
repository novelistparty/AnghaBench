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
struct ttm_lock {scalar_t__ rw; scalar_t__ flags; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool __ttm_read_lock(struct ttm_lock *lock)
{
	bool locked = false;

	spin_lock(&lock->lock);
	if (lock->rw >= 0 && lock->flags == 0) {
		++lock->rw;
		locked = true;
	}
	spin_unlock(&lock->lock);
	return locked;
}