#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int* rsc; int* idd; } ;
struct TYPE_5__ {int* ipacket; TYPE_1__ di_scratch; } ;
typedef  TYPE_2__ hil_mlc ;

/* Variables and functions */
 int HILSEN_NEXT ; 
 int HIL_IDD_HEADER_EXD ; 
 int HIL_PKT_DATA_MASK ; 

__attribute__((used)) static int hilse_take_rsc(hil_mlc *mlc, int unused)
{
	int i;

	for (i = 0; i < 16; i++)
		mlc->di_scratch.rsc[i] =
			mlc->ipacket[i] & HIL_PKT_DATA_MASK;

	/* Next step is to see if EXD supported (IDD has already been read) */
	if (mlc->di_scratch.idd[1] & HIL_IDD_HEADER_EXD)
		return HILSEN_NEXT;

	return 0;
}