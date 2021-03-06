#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ speed; } ;
struct TYPE_4__ {int /*<<< orphan*/  irqs_suspend; } ;
struct pxa_udc {TYPE_3__ gadget; TYPE_2__* driver; TYPE_1__ stats; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* suspend ) (TYPE_3__*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  UDCISR1 ; 
 int /*<<< orphan*/  UDCISR1_IRSU ; 
 scalar_t__ USB_SPEED_UNKNOWN ; 
 int /*<<< orphan*/  ep0_idle (struct pxa_udc*) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*) ; 
 int /*<<< orphan*/  udc_writel (struct pxa_udc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void irq_udc_suspend(struct pxa_udc *udc)
{
	udc_writel(udc, UDCISR1, UDCISR1_IRSU);
	udc->stats.irqs_suspend++;

	if (udc->gadget.speed != USB_SPEED_UNKNOWN
			&& udc->driver && udc->driver->suspend)
		udc->driver->suspend(&udc->gadget);
	ep0_idle(udc);
}