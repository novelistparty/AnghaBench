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
struct xhci_hcd {int hci_version; int /*<<< orphan*/  quirks; int /*<<< orphan*/  lock; } ;
struct usb_hcd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  XHCI_COMP_MODE_QUIRK ; 
 int /*<<< orphan*/  XHCI_LINK_TRB_QUIRK ; 
 int /*<<< orphan*/  compliance_mode_recovery_timer_init (struct xhci_hcd*) ; 
 scalar_t__ compliance_mode_recovery_timer_quirk_check () ; 
 struct xhci_hcd* hcd_to_xhci (struct usb_hcd*) ; 
 scalar_t__ link_quirk ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xhci_dbg (struct xhci_hcd*,char*) ; 
 int xhci_mem_init (struct xhci_hcd*,int /*<<< orphan*/ ) ; 

int xhci_init(struct usb_hcd *hcd)
{
	struct xhci_hcd *xhci = hcd_to_xhci(hcd);
	int retval = 0;

	xhci_dbg(xhci, "xhci_init\n");
	spin_lock_init(&xhci->lock);
	if (xhci->hci_version == 0x95 && link_quirk) {
		xhci_dbg(xhci, "QUIRK: Not clearing Link TRB chain bits.\n");
		xhci->quirks |= XHCI_LINK_TRB_QUIRK;
	} else {
		xhci_dbg(xhci, "xHCI doesn't need link TRB QUIRK\n");
	}
	retval = xhci_mem_init(xhci, GFP_KERNEL);
	xhci_dbg(xhci, "Finished xhci_init\n");

	/* Initializing Compliance Mode Recovery Data If Needed */
	if (compliance_mode_recovery_timer_quirk_check()) {
		xhci->quirks |= XHCI_COMP_MODE_QUIRK;
		compliance_mode_recovery_timer_init(xhci);
	}

	return retval;
}