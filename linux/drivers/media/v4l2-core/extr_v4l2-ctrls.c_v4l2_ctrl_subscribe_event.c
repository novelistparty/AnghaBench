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
struct v4l2_fh {int dummy; } ;
struct v4l2_event_subscription {scalar_t__ type; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ V4L2_EVENT_CTRL ; 
 int /*<<< orphan*/  v4l2_ctrl_sub_ev_ops ; 
 int v4l2_event_subscribe (struct v4l2_fh*,struct v4l2_event_subscription const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int v4l2_ctrl_subscribe_event(struct v4l2_fh *fh,
				const struct v4l2_event_subscription *sub)
{
	if (sub->type == V4L2_EVENT_CTRL)
		return v4l2_event_subscribe(fh, sub, 0, &v4l2_ctrl_sub_ev_ops);
	return -EINVAL;
}