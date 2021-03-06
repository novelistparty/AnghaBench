#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT ;
struct TYPE_3__ {int /*<<< orphan*/  AdminOptionList; } ;
typedef  TYPE_1__ HUB ;

/* Variables and functions */
 int /*<<< orphan*/  DeleteAll (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LIST_DATA (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ LIST_NUM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LockList (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  UnlockList (int /*<<< orphan*/ ) ; 

void DeleteAllHubAdminOption(HUB *h, bool lock)
{
	UINT i;
	// Validate arguments
	if (h == NULL)
	{
		return;
	}

	if (lock)
	{
		LockList(h->AdminOptionList);
	}

	for (i = 0;i < LIST_NUM(h->AdminOptionList);i++)
	{
		Free(LIST_DATA(h->AdminOptionList, i));
	}

	DeleteAll(h->AdminOptionList);

	if (lock)
	{
		UnlockList(h->AdminOptionList);
	}
}