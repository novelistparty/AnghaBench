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
struct TYPE_2__ {int status; } ;

/* Variables and functions */
 int IRQ_DISABLED ; 
 int IRQ_INPROGRESS ; 
 TYPE_1__* irq_desc ; 
 int /*<<< orphan*/  noritake_enable_irq (unsigned int) ; 

__attribute__((used)) static void
noritake_end_irq(unsigned int irq)
{
        if (!(irq_desc[irq].status & (IRQ_DISABLED|IRQ_INPROGRESS)))
                noritake_enable_irq(irq);
}