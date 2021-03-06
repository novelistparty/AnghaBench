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
struct _Locale_monetary {int dummy; } ;
typedef  int /*<<< orphan*/  locale_t ;

/* Variables and functions */
 int /*<<< orphan*/  MON_GROUPING ; 
 scalar_t__ _Locale_mon_thousands_sep (struct _Locale_monetary*) ; 
 char const* _empty_str ; 
 char const* nl_langinfo_l (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

const char *_Locale_mon_grouping(struct _Locale_monetary *__loc)
{
  return (_Locale_mon_thousands_sep( __loc ) != 0 ) ? nl_langinfo_l(MON_GROUPING, (locale_t)__loc) : _empty_str;
}