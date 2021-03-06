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
 int /*<<< orphan*/  die (char*) ; 
 int /*<<< orphan*/  release_pack_memory (scalar_t__,int) ; 
 char* strdup (char const*) ; 
 scalar_t__ strlen (char const*) ; 

char *xstrdup(const char *str)
{
	char *ret = strdup(str);
	if (!ret) {
		release_pack_memory(strlen(str) + 1, -1);
		ret = strdup(str);
		if (!ret)
			die("Out of memory, strdup failed");
	}
	return ret;
}