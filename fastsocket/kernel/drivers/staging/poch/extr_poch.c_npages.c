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
 unsigned long PAGE_SIZE ; 

__attribute__((used)) static unsigned long npages(unsigned long bytes)
{
	if (bytes % PAGE_SIZE == 0)
		return bytes / PAGE_SIZE;
	else
		return (bytes / PAGE_SIZE) + 1;
}