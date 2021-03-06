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
typedef  int u64 ;
typedef  int u32 ;
struct ipath_devdata {int ibcs_lts_mask; int ibcs_ls_shift; } ;

/* Variables and functions */
 int INFINIPATH_IBCS_LINKSTATE_MASK ; 
 int INFINIPATH_IBCS_LINKTRAININGSTATE_SHIFT ; 

__attribute__((used)) static inline u32 ipath_ib_state(struct ipath_devdata *dd, u64 ibcs)
{
	u32 ibs;
	ibs = (u32)(ibcs >> INFINIPATH_IBCS_LINKTRAININGSTATE_SHIFT) &
		dd->ibcs_lts_mask;
	ibs |= (u32)(ibcs &
		(INFINIPATH_IBCS_LINKSTATE_MASK << dd->ibcs_ls_shift));
	return ibs;
}