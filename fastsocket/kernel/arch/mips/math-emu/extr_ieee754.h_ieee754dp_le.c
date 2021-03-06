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
typedef  int /*<<< orphan*/  ieee754dp ;

/* Variables and functions */
 int IEEE754_CEQ ; 
 int IEEE754_CLT ; 
 int ieee754dp_cmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int ieee754dp_le(ieee754dp x, ieee754dp y)
{
	return ieee754dp_cmp(x, y, IEEE754_CLT | IEEE754_CEQ, 0);
}