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
struct v4l2_subdev {int dummy; } ;
struct v4l2_control {int id; int /*<<< orphan*/  value; } ;
struct adv7343_state {int /*<<< orphan*/  gain; int /*<<< orphan*/  hue; int /*<<< orphan*/  bright; } ;

/* Variables and functions */
 int EINVAL ; 
#define  V4L2_CID_BRIGHTNESS 130 
#define  V4L2_CID_GAIN 129 
#define  V4L2_CID_HUE 128 
 struct adv7343_state* to_state (struct v4l2_subdev*) ; 

__attribute__((used)) static int adv7343_g_ctrl(struct v4l2_subdev *sd, struct v4l2_control *ctrl)
{
	struct adv7343_state *state = to_state(sd);

	switch (ctrl->id) {
	case V4L2_CID_BRIGHTNESS:
		ctrl->value = state->bright;
		break;

	case V4L2_CID_HUE:
		ctrl->value = state->hue;
		break;

	case V4L2_CID_GAIN:
		ctrl->value = state->gain;
		break;

	default:
		return -EINVAL;
	}

	return 0;
}