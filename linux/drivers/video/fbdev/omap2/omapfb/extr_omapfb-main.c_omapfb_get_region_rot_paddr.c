#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct omapfb_info {scalar_t__ rotation_type; TYPE_2__* region; } ;
struct TYPE_3__ {scalar_t__* paddr; } ;
struct TYPE_4__ {scalar_t__ paddr; TYPE_1__ vrfb; } ;

/* Variables and functions */
 scalar_t__ OMAP_DSS_ROT_VRFB ; 
 scalar_t__ omapfb_get_vrfb_offset (struct omapfb_info const*,int) ; 

__attribute__((used)) static u32 omapfb_get_region_rot_paddr(const struct omapfb_info *ofbi, int rot)
{
	if (ofbi->rotation_type == OMAP_DSS_ROT_VRFB) {
		return ofbi->region->vrfb.paddr[rot]
			+ omapfb_get_vrfb_offset(ofbi, rot);
	} else {
		return ofbi->region->paddr;
	}
}