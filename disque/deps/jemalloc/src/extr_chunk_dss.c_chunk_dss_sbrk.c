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
 int /*<<< orphan*/  not_implemented () ; 
 void* sbrk (intptr_t) ; 

__attribute__((used)) static void *
chunk_dss_sbrk(intptr_t increment)
{

#ifdef JEMALLOC_DSS
	return (sbrk(increment));
#else
	not_implemented();
	return (NULL);
#endif
}