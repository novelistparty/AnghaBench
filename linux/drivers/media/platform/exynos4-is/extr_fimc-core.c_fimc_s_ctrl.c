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
struct v4l2_ctrl {int dummy; } ;
struct fimc_ctx {TYPE_1__* fimc_dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  slock; } ;

/* Variables and functions */
 int __fimc_s_ctrl (struct fimc_ctx*,struct v4l2_ctrl*) ; 
 struct fimc_ctx* ctrl_to_ctx (struct v4l2_ctrl*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int fimc_s_ctrl(struct v4l2_ctrl *ctrl)
{
	struct fimc_ctx *ctx = ctrl_to_ctx(ctrl);
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&ctx->fimc_dev->slock, flags);
	ret = __fimc_s_ctrl(ctx, ctrl);
	spin_unlock_irqrestore(&ctx->fimc_dev->slock, flags);

	return ret;
}