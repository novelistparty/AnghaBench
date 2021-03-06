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
 unsigned int clamp (unsigned int,unsigned int,unsigned int) ; 
 unsigned int round_up (unsigned int,unsigned int) ; 

__attribute__((used)) static unsigned int clamp_roundup(unsigned int x, unsigned int min,
				   unsigned int max, unsigned int alignment)
{
	x = clamp(x, min, max);
	if (alignment)
		x = round_up(x, alignment);

	return x;
}