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
struct vpdma_dtd {int type_ctl_stride; } ;

/* Variables and functions */
 int DTD_ODD_LINE_SKIP_MASK ; 
 int DTD_ODD_LINE_SKIP_SHFT ; 

__attribute__((used)) static inline bool dtd_get_odd_line_skip(struct vpdma_dtd *dtd)
{
	return (dtd->type_ctl_stride >> DTD_ODD_LINE_SKIP_SHFT)
		& DTD_ODD_LINE_SKIP_MASK;
}