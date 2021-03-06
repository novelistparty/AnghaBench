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
struct tty_ldisc_ops {int /*<<< orphan*/  owner; int /*<<< orphan*/  refcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tty_ldisc_lock ; 

__attribute__((used)) static void put_ldops(struct tty_ldisc_ops *ldops)
{
	unsigned long flags;

	spin_lock_irqsave(&tty_ldisc_lock, flags);
	ldops->refcount--;
	module_put(ldops->owner);
	spin_unlock_irqrestore(&tty_ldisc_lock, flags);
}