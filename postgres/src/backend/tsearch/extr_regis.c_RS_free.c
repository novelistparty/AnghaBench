#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* node; } ;
struct TYPE_5__ {struct TYPE_5__* next; } ;
typedef  TYPE_1__ RegisNode ;
typedef  TYPE_2__ Regis ;

/* Variables and functions */
 int /*<<< orphan*/  pfree (TYPE_1__*) ; 

void
RS_free(Regis *r)
{
	RegisNode  *ptr = r->node,
			   *tmp;

	while (ptr)
	{
		tmp = ptr->next;
		pfree(ptr);
		ptr = tmp;
	}

	r->node = NULL;
}