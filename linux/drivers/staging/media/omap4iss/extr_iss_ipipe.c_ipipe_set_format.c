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
struct v4l2_subdev_pad_config {int dummy; } ;
struct v4l2_mbus_framefmt {int dummy; } ;
struct v4l2_subdev_format {int /*<<< orphan*/  which; struct v4l2_mbus_framefmt format; int /*<<< orphan*/  pad; } ;
struct v4l2_subdev {int dummy; } ;
struct iss_ipipe_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  IPIPE_PAD_SINK ; 
 int /*<<< orphan*/  IPIPE_PAD_SOURCE_VP ; 
 struct v4l2_mbus_framefmt* __ipipe_get_format (struct iss_ipipe_device*,struct v4l2_subdev_pad_config*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ipipe_try_format (struct iss_ipipe_device*,struct v4l2_subdev_pad_config*,int /*<<< orphan*/ ,struct v4l2_mbus_framefmt*,int /*<<< orphan*/ ) ; 
 struct iss_ipipe_device* v4l2_get_subdevdata (struct v4l2_subdev*) ; 

__attribute__((used)) static int ipipe_set_format(struct v4l2_subdev *sd,
			    struct v4l2_subdev_pad_config *cfg,
			    struct v4l2_subdev_format *fmt)
{
	struct iss_ipipe_device *ipipe = v4l2_get_subdevdata(sd);
	struct v4l2_mbus_framefmt *format;

	format = __ipipe_get_format(ipipe, cfg, fmt->pad, fmt->which);
	if (!format)
		return -EINVAL;

	ipipe_try_format(ipipe, cfg, fmt->pad, &fmt->format, fmt->which);
	*format = fmt->format;

	/* Propagate the format from sink to source */
	if (fmt->pad == IPIPE_PAD_SINK) {
		format = __ipipe_get_format(ipipe, cfg, IPIPE_PAD_SOURCE_VP,
					    fmt->which);
		*format = fmt->format;
		ipipe_try_format(ipipe, cfg, IPIPE_PAD_SOURCE_VP, format,
				 fmt->which);
	}

	return 0;
}