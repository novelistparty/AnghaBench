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
typedef  int /*<<< orphan*/  memory_object_t ;
typedef  int /*<<< orphan*/  fourk_pager_t ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  PAGER_ALL ; 
 int /*<<< orphan*/  PAGER_DEBUG (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  fourk_pager_deallocate_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fourk_pager_lookup (int /*<<< orphan*/ ) ; 

void
fourk_pager_deallocate(
	memory_object_t		mem_obj)
{
	fourk_pager_t	pager;

	PAGER_DEBUG(PAGER_ALL, ("fourk_pager_deallocate: %p\n", mem_obj));
	pager = fourk_pager_lookup(mem_obj);
	fourk_pager_deallocate_internal(pager, FALSE);
}