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
struct dw_hdmi {int /*<<< orphan*/  bridge; } ;

/* Variables and functions */
 int /*<<< orphan*/  __dw_hdmi_remove (struct dw_hdmi*) ; 
 int /*<<< orphan*/  drm_bridge_remove (int /*<<< orphan*/ *) ; 

void dw_hdmi_remove(struct dw_hdmi *hdmi)
{
	drm_bridge_remove(&hdmi->bridge);

	__dw_hdmi_remove(hdmi);
}