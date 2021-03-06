#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  elements; } ;
typedef  TYPE_1__ PACK ;

/* Variables and functions */
 int /*<<< orphan*/  ComparePackName ; 
 int /*<<< orphan*/  NewListFast (int /*<<< orphan*/ ) ; 
 TYPE_1__* ZeroMallocEx (int,int) ; 

PACK *NewPack()
{
	PACK *p;

	// Memory allocation
	p = ZeroMallocEx(sizeof(PACK), true);

	// Creating a List
	p->elements = NewListFast(ComparePackName);

	return p;
}