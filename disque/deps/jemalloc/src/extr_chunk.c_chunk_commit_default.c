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
 int pages_commit (void*,size_t) ; 

__attribute__((used)) static bool
chunk_commit_default(void *chunk, size_t size, size_t offset, size_t length,
    unsigned arena_ind)
{

	return (pages_commit((void *)((uintptr_t)chunk + (uintptr_t)offset),
	    length));
}