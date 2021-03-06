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
struct timeval {int dummy; } ;
struct proc {int /*<<< orphan*/  p_crux; } ;

/* Variables and functions */
 int /*<<< orphan*/  MA_OWNED ; 
 int /*<<< orphan*/  PROC_LOCK_ASSERT (struct proc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  calcru1 (struct proc*,int /*<<< orphan*/ *,struct timeval*,struct timeval*) ; 

void
calccru(struct proc *p, struct timeval *up, struct timeval *sp)
{

	PROC_LOCK_ASSERT(p, MA_OWNED);
	calcru1(p, &p->p_crux, up, sp);
}