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
typedef  int fexcept_t ;

/* Variables and functions */
 int FE_ALL_EXCEPT ; 
 int /*<<< orphan*/  __cfc1 (int) ; 

inline int
fegetexceptflag(fexcept_t *__flagp, int __excepts)
{
	fexcept_t fcsr;

	__excepts &= FE_ALL_EXCEPT;
	__cfc1(fcsr);
	*__flagp = fcsr & __excepts;

	return (0);
}