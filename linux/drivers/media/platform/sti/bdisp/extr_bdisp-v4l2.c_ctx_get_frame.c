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
struct bdisp_frame {int dummy; } ;
struct bdisp_ctx {TYPE_1__* bdisp_dev; struct bdisp_frame dst; struct bdisp_frame src; } ;
typedef  enum v4l2_buf_type { ____Placeholder_v4l2_buf_type } v4l2_buf_type ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 struct bdisp_frame* ERR_PTR (int /*<<< orphan*/ ) ; 
#define  V4L2_BUF_TYPE_VIDEO_CAPTURE 129 
#define  V4L2_BUF_TYPE_VIDEO_OUTPUT 128 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static struct bdisp_frame *ctx_get_frame(struct bdisp_ctx *ctx,
					 enum v4l2_buf_type type)
{
	switch (type) {
	case V4L2_BUF_TYPE_VIDEO_OUTPUT:
		return &ctx->src;
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		return &ctx->dst;
	default:
		dev_err(ctx->bdisp_dev->dev,
			"Wrong buffer/video queue type (%d)\n", type);
		break;
	}

	return ERR_PTR(-EINVAL);
}