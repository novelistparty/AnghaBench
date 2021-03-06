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
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 char const* svn_utf__cstring_from_utf8_fuzzy (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_utf_cstring_from_utf8 ; 

const char *
svn_utf_cstring_from_utf8_fuzzy(const char *src,
                                apr_pool_t *pool)
{
  return svn_utf__cstring_from_utf8_fuzzy(src, pool,
                                          svn_utf_cstring_from_utf8);
}