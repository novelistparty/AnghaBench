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
typedef  int /*<<< orphan*/  nvpair_t ;
typedef  int /*<<< orphan*/  nvlist_t ;

/* Variables and functions */
 int /*<<< orphan*/ * nvlist_next_nvpair (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

size_t
fnvlist_num_pairs(nvlist_t *nvl)
{
	size_t count = 0;
	nvpair_t *pair;

	for (pair = nvlist_next_nvpair(nvl, 0); pair != NULL;
	    pair = nvlist_next_nvpair(nvl, pair))
		count++;
	return (count);
}