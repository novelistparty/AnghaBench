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
 void* vmalloc (unsigned long) ; 
 void* vmalloc_exec (unsigned long) ; 

void *module_alloc(unsigned long size)
{
	if (size == 0)
		return NULL;
#ifdef CONFIG_MMU
	return vmalloc_exec(size);
#else
	return vmalloc(size);
#endif
}