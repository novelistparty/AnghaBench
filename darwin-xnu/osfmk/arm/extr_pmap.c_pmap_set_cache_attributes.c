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
typedef  int /*<<< orphan*/  ppnum_t ;

/* Variables and functions */
 int /*<<< orphan*/  pmap_set_cache_attributes_internal (int /*<<< orphan*/ ,unsigned int) ; 

void
pmap_set_cache_attributes(
	ppnum_t pn,
	unsigned int cacheattr)
{
	pmap_set_cache_attributes_internal(pn, cacheattr);
}