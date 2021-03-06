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
struct sscape_info {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __sscape_write (int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void sscape_write(struct sscape_info *devc, int reg, int data)
{
	unsigned long flags;

	spin_lock_irqsave(&devc->lock,flags);
	__sscape_write(reg, data);
	spin_unlock_irqrestore(&devc->lock,flags);
}