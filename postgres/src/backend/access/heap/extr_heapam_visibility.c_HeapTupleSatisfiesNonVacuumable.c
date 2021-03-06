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
struct TYPE_3__ {int /*<<< orphan*/  xmin; } ;
typedef  TYPE_1__* Snapshot ;
typedef  int /*<<< orphan*/  HeapTuple ;
typedef  int /*<<< orphan*/  Buffer ;

/* Variables and functions */
 scalar_t__ HEAPTUPLE_DEAD ; 
 scalar_t__ HeapTupleSatisfiesVacuum (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
HeapTupleSatisfiesNonVacuumable(HeapTuple htup, Snapshot snapshot,
								Buffer buffer)
{
	return HeapTupleSatisfiesVacuum(htup, snapshot->xmin, buffer)
		!= HEAPTUPLE_DEAD;
}