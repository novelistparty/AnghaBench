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
typedef  int /*<<< orphan*/  u32 ;
struct usb_hcd {scalar_t__ regs; } ;
struct isp1760_hcd {int i_thresh; int /*<<< orphan*/  periodic_size; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEFAULT_I_TDPS ; 
 scalar_t__ HCC_ISOC_CACHE (int /*<<< orphan*/ ) ; 
 int HCC_ISOC_THRES (int /*<<< orphan*/ ) ; 
 scalar_t__ HC_HCCPARAMS ; 
 struct isp1760_hcd* hcd_to_priv (struct usb_hcd*) ; 
 int /*<<< orphan*/  isp1760_readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int priv_init(struct usb_hcd *hcd)
{
	struct isp1760_hcd		*priv = hcd_to_priv(hcd);
	u32			hcc_params;

	spin_lock_init(&priv->lock);

	/*
	 * hw default: 1K periodic list heads, one per frame.
	 * periodic_size can shrink by USBCMD update if hcc_params allows.
	 */
	priv->periodic_size = DEFAULT_I_TDPS;

	/* controllers may cache some of the periodic schedule ... */
	hcc_params = isp1760_readl(hcd->regs + HC_HCCPARAMS);
	/* full frame cache */
	if (HCC_ISOC_CACHE(hcc_params))
		priv->i_thresh = 8;
	else /* N microframes cached */
		priv->i_thresh = 2 + HCC_ISOC_THRES(hcc_params);

	return 0;
}