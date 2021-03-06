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
typedef  int u64 ;

/* Variables and functions */
 int cacheline_size () ; 

__attribute__((used)) static inline u64 cl_address(u64 address)
{
	/* return the cacheline of the address */
	return (address & ~(cacheline_size() - 1));
}