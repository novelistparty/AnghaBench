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
struct TYPE_2__ {int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ TABLE ;

/* Variables and functions */
 int StrCmpi (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int CmpTableName(void *p1, void *p2)
{
	TABLE *t1, *t2;
	if (p1 == NULL || p2 == NULL)
	{
		return 0;
	}
	t1 = *(TABLE **)p1;
	t2 = *(TABLE **)p2;
	if (t1 == NULL || t2 == NULL)
	{
		return 0;
	}

	return StrCmpi(t1->name, t2->name);
}