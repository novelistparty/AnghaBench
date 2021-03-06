#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u_int32_t ;
typedef  int /*<<< orphan*/  u_int16_t ;
struct TYPE_8__ {TYPE_2__* ldSpanMap; } ;
struct TYPE_9__ {TYPE_3__ raidMap; } ;
struct TYPE_6__ {int /*<<< orphan*/  targetId; } ;
struct TYPE_7__ {TYPE_1__ ldRaid; } ;
typedef  TYPE_4__ MR_DRV_RAID_MAP_ALL ;

/* Variables and functions */

u_int16_t
MR_GetLDTgtId(u_int32_t ld, MR_DRV_RAID_MAP_ALL * map)
{
	return (map->raidMap.ldSpanMap[ld].ldRaid.targetId);
}