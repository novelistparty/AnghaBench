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

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int roundup (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tw68_buffer_count(unsigned int size, unsigned int count)
{
	unsigned int maxcount;

	maxcount = (4 * 1024 * 1024) / roundup(size, PAGE_SIZE);
	if (count > maxcount)
		count = maxcount;
	return count;
}