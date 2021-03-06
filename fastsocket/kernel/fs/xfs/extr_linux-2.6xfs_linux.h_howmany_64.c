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
typedef  int /*<<< orphan*/  __uint64_t ;
typedef  int __uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  do_div (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline __uint64_t howmany_64(__uint64_t x, __uint32_t y)
{
	x += y - 1;
	do_div(x, y);
	return x;
}