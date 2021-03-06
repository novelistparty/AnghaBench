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
struct controller {int notification_enabled; } ;

/* Variables and functions */
 scalar_t__ pcie_enable_notification (struct controller*) ; 
 int /*<<< orphan*/  pciehp_free_irq (struct controller*) ; 
 scalar_t__ pciehp_request_irq (struct controller*) ; 

int pcie_init_notification(struct controller *ctrl)
{
	if (pciehp_request_irq(ctrl))
		return -1;
	if (pcie_enable_notification(ctrl)) {
		pciehp_free_irq(ctrl);
		return -1;
	}
	ctrl->notification_enabled = 1;
	return 0;
}