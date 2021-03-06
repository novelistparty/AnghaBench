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
 int /*<<< orphan*/  __reschedule_timeout (int,char const*,int) ; 
 int /*<<< orphan*/  floppy_lock ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void reschedule_timeout(int drive, const char *message, int marg)
{
	unsigned long flags;

	spin_lock_irqsave(&floppy_lock, flags);
	__reschedule_timeout(drive, message, marg);
	spin_unlock_irqrestore(&floppy_lock, flags);
}