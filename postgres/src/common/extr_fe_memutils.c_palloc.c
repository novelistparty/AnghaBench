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
typedef  int /*<<< orphan*/  Size ;

/* Variables and functions */
 void* pg_malloc_internal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void *
palloc(Size size)
{
	return pg_malloc_internal(size, 0);
}