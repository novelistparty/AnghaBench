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
struct pvr2_hdw {unsigned int control_cnt; } ;

/* Variables and functions */

unsigned int pvr2_hdw_get_ctrl_count(struct pvr2_hdw *hdw)
{
	return hdw->control_cnt;
}