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
typedef  int /*<<< orphan*/  wint_t ;

/* Variables and functions */
 int /*<<< orphan*/  _CTYPE_U ; 
 int __istype (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
iswupper(wint_t wc)
{
	return (__istype(wc, _CTYPE_U));
}