#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ IpAddress; } ;
typedef  TYPE_1__ L3ARPENTRY ;

/* Variables and functions */

int CmpL3ArpEntry(void *p1, void *p2)
{
	L3ARPENTRY *e1, *e2;
	if (p1 == NULL || p2 == NULL)
	{
		return 0;
	}
	e1 = *(L3ARPENTRY **)p1;
	e2 = *(L3ARPENTRY **)p2;
	if (e1 == NULL || e2 == NULL)
	{
		return 0;
	}
	if (e1->IpAddress > e2->IpAddress)
	{
		return 1;
	}
	else if (e1->IpAddress < e2->IpAddress)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}