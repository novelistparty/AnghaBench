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
struct TYPE_2__ {size_t cmin; } ;
typedef  size_t CommandId ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 TYPE_1__* comboCids ; 
 size_t usedComboCids ; 

__attribute__((used)) static CommandId
GetRealCmin(CommandId combocid)
{
	Assert(combocid < usedComboCids);
	return comboCids[combocid].cmin;
}