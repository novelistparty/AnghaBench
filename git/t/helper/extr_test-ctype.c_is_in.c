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
 int /*<<< orphan*/  strchr (char const*,int) ; 

__attribute__((used)) static int is_in(const char *s, int ch)
{
	/* We can't find NUL using strchr.  It's classless anyway. */
	if (ch == '\0')
		return 0;
	return !!strchr(s, ch);
}