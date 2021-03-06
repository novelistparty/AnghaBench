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
struct videobuf_queue {int dummy; } ;
struct v4l2_m2m_ctx {int dummy; } ;
struct file {int dummy; } ;
typedef  enum v4l2_buf_type { ____Placeholder_v4l2_buf_type } v4l2_buf_type ;

/* Variables and functions */
 struct videobuf_queue* v4l2_m2m_get_vq (struct v4l2_m2m_ctx*,int) ; 
 int /*<<< orphan*/  v4l2_m2m_try_schedule (struct v4l2_m2m_ctx*) ; 
 int videobuf_streamon (struct videobuf_queue*) ; 

int v4l2_m2m_streamon(struct file *file, struct v4l2_m2m_ctx *m2m_ctx,
		      enum v4l2_buf_type type)
{
	struct videobuf_queue *vq;
	int ret;

	vq = v4l2_m2m_get_vq(m2m_ctx, type);
	ret = videobuf_streamon(vq);
	if (!ret)
		v4l2_m2m_try_schedule(m2m_ctx);

	return ret;
}