#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct COverflowData {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (struct COverflowData*) ; 
 int /*<<< orphan*/  DIVREM_STRING ; 
 int /*<<< orphan*/  HandleOverflow (int,struct COverflowData*,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 

void
__ubsan_handle_divrem_overflow(struct COverflowData *pData, unsigned long ulLHS, unsigned long ulRHS)
{

	ASSERT(pData);

	HandleOverflow(false, pData, ulLHS, ulRHS, DIVREM_STRING);
}