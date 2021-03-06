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
struct vmw_private {struct fb_info* fb_info; } ;
struct TYPE_2__ {int active; int /*<<< orphan*/  lock; } ;
struct vmw_fb_par {int /*<<< orphan*/  local_work; TYPE_1__ dirty; } ;
struct fb_info {struct vmw_fb_par* par; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  schedule_delayed_work (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int vmw_fb_on(struct vmw_private *vmw_priv)
{
	struct fb_info *info;
	struct vmw_fb_par *par;
	unsigned long flags;

	if (!vmw_priv->fb_info)
		return -EINVAL;

	info = vmw_priv->fb_info;
	par = info->par;

	spin_lock_irqsave(&par->dirty.lock, flags);
	par->dirty.active = true;
	spin_unlock_irqrestore(&par->dirty.lock, flags);

	/*
	 * Need to reschedule a dirty update, because otherwise that's
	 * only done in dirty_mark() if the previous coalesced
	 * dirty region was empty.
	 */
	schedule_delayed_work(&par->local_work, 0);

	return 0;
}