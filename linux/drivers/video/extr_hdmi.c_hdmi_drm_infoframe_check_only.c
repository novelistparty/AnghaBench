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
struct hdmi_drm_infoframe {scalar_t__ type; int version; scalar_t__ length; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ HDMI_DRM_INFOFRAME_SIZE ; 
 scalar_t__ HDMI_INFOFRAME_TYPE_DRM ; 

__attribute__((used)) static int hdmi_drm_infoframe_check_only(const struct hdmi_drm_infoframe *frame)
{
	if (frame->type != HDMI_INFOFRAME_TYPE_DRM ||
	    frame->version != 1)
		return -EINVAL;

	if (frame->length != HDMI_DRM_INFOFRAME_SIZE)
		return -EINVAL;

	return 0;
}