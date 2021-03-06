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
typedef  int /*<<< orphan*/  u64 ;

/* Variables and functions */
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_ALL_OPC ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_ISOC ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_LINK ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_LOC ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_NC ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_NM ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_NOT_NM ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_OPC0 ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_OPC1 ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_REM ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_STATE ; 
 int /*<<< orphan*/  SKX_CHA_MSR_PMON_BOX_FILTER_TID ; 

__attribute__((used)) static u64 skx_cha_filter_mask(int fields)
{
	u64 mask = 0;

	if (fields & 0x1)
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_TID;
	if (fields & 0x2)
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_LINK;
	if (fields & 0x4)
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_STATE;
	if (fields & 0x8) {
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_REM;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_LOC;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_ALL_OPC;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_NM;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_NOT_NM;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_OPC0;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_OPC1;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_NC;
		mask |= SKX_CHA_MSR_PMON_BOX_FILTER_ISOC;
	}
	return mask;
}