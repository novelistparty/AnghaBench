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
 size_t strlen (char const*) ; 

__attribute__((used)) static int
getRightMostDot(const char *str)
{
	size_t		len = strlen(str);
	int			i,
				j;

	j = 0;
	for (i = len - 1; i >= 0; i--)
	{
		if (str[i] == '.')
			return len - j - 1;
		j++;
	}
	return -1;
}