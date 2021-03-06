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

/* Variables and functions */
 int /*<<< orphan*/  _pending_exceptions_done ; 
 int /*<<< orphan*/  _pending_exceptions_done_count ; 
 int /*<<< orphan*/  _pending_exceptions_done_spinlock ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wake_up_all (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void increment_pending_exceptions_done_count(void)
{
	spin_lock(&_pending_exceptions_done_spinlock);
	_pending_exceptions_done_count++;
	spin_unlock(&_pending_exceptions_done_spinlock);

	wake_up_all(&_pending_exceptions_done);
}