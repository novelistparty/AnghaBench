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
struct TYPE_3__ {scalar_t__ initialized; int /*<<< orphan*/ * m_owner; int /*<<< orphan*/  m_lock; } ;
typedef  TYPE_1__ kmutex_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ B_FALSE ; 
 scalar_t__ B_TRUE ; 
 int /*<<< orphan*/  _mutex_destroy (int /*<<< orphan*/ *) ; 

void
zmutex_destroy(kmutex_t *mp)
{
	ASSERT(mp->initialized == B_TRUE);
	ASSERT(mp->m_owner == NULL);
	(void) _mutex_destroy(&(mp)->m_lock);
	mp->m_owner = (void *)-1UL;
	mp->initialized = B_FALSE;
}