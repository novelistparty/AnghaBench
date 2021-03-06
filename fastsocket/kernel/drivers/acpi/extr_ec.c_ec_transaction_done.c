#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct acpi_ec {int /*<<< orphan*/  curr_lock; TYPE_1__* curr; } ;
struct TYPE_2__ {scalar_t__ done; } ;

/* Variables and functions */
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int ec_transaction_done(struct acpi_ec *ec)
{
	unsigned long flags;
	int ret = 0;
	spin_lock_irqsave(&ec->curr_lock, flags);
	if (!ec->curr || ec->curr->done)
		ret = 1;
	spin_unlock_irqrestore(&ec->curr_lock, flags);
	return ret;
}