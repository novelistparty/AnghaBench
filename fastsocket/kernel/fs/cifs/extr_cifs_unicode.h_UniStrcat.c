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
typedef  int /*<<< orphan*/  wchar_t ;

/* Variables and functions */

__attribute__((used)) static inline wchar_t *
UniStrcat(wchar_t *ucs1, const wchar_t *ucs2)
{
	wchar_t *anchor = ucs1;	/* save a pointer to start of ucs1 */

	while (*ucs1++) ;	/* To end of first string */
	ucs1--;			/* Return to the null */
	while ((*ucs1++ = *ucs2++)) ;	/* copy string 2 over */
	return anchor;
}