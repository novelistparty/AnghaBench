#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {void* curcid; } ;
struct TYPE_3__ {void* curcid; } ;
typedef  void* CommandId ;

/* Variables and functions */
 TYPE_2__* CurrentSnapshot ; 
 int /*<<< orphan*/  FirstSnapshotSet ; 
 TYPE_1__* SecondarySnapshot ; 

void
SnapshotSetCommandId(CommandId curcid)
{
	if (!FirstSnapshotSet)
		return;

	if (CurrentSnapshot)
		CurrentSnapshot->curcid = curcid;
	if (SecondarySnapshot)
		SecondarySnapshot->curcid = curcid;
	/* Should we do the same with CatalogSnapshot? */
}