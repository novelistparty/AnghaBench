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
typedef  union ocfs2_dlm_lksb {int dummy; } ocfs2_dlm_lksb ;

/* Variables and functions */

__attribute__((used)) static int o2cb_dlm_lvb_valid(union ocfs2_dlm_lksb *lksb)
{
	return 1;
}