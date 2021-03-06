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
typedef  unsigned long uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int secsz ; 

__attribute__((used)) static int
is_empty_sector(void *buf)
{
	uint64_t *p = buf;
	size_t n, max;

	assert(((uintptr_t)p & 3) == 0);

	max = secsz / sizeof(uint64_t);
	for (n = 0; n < max; n++) {
		if (p[n] != 0UL)
			return (0);
	}
	return (1);
}