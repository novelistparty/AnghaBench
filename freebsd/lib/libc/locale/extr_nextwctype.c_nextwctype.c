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
typedef  int /*<<< orphan*/  wctype_t ;

/* Variables and functions */
 int /*<<< orphan*/  __get_locale () ; 
 int /*<<< orphan*/  nextwctype_l (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

wint_t
nextwctype(wint_t wc, wctype_t wct)
{
	return nextwctype_l(wc, wct, __get_locale());
}