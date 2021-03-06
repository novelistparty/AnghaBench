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
struct TYPE_3__ {int size; int /*<<< orphan*/  heap; int /*<<< orphan*/ ** order; } ;
typedef  TYPE_1__ PriorityQ ;
typedef  int /*<<< orphan*/  PQkey ;

/* Variables and functions */
 scalar_t__ LEQ (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pqHeapIsEmpty (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pqHeapMinimum (int /*<<< orphan*/ ) ; 

PQkey pqMinimum( PriorityQ *pq )
{
	PQkey sortMin, heapMin;

	if( pq->size == 0 ) {
		return pqHeapMinimum( pq->heap );
	}
	sortMin = *(pq->order[pq->size-1]);
	if( ! pqHeapIsEmpty( pq->heap )) {
		heapMin = pqHeapMinimum( pq->heap );
		if( LEQ( heapMin, sortMin )) {
			return heapMin;
		}
	}
	return sortMin;
}