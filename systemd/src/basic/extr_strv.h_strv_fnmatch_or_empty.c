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
 int /*<<< orphan*/  assert (char const*) ; 
 scalar_t__ strv_fnmatch (char* const*,char const*,int) ; 
 scalar_t__ strv_isempty (char* const*) ; 

__attribute__((used)) static inline bool strv_fnmatch_or_empty(char* const* patterns, const char *s, int flags) {
        assert(s);
        return strv_isempty(patterns) ||
               strv_fnmatch(patterns, s, flags);
}