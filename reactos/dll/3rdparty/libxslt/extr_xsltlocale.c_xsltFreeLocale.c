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
typedef  int /*<<< orphan*/  xsltLocale ;

/* Variables and functions */
 int /*<<< orphan*/  freelocale (int /*<<< orphan*/ ) ; 

void
xsltFreeLocale(xsltLocale locale) {
#ifdef XSLT_LOCALE_POSIX
    freelocale(locale);
#endif
}