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
 int strcmp (char*,char*) ; 

int StrCmp(char *str1, char *str2)
{
	// Validate arguments
	if (str1 == NULL && str2 == NULL)
	{
		return 0;
	}
	if (str1 == NULL)
	{
		return 1;
	}
	if (str2 == NULL)
	{
		return -1;
	}

	return strcmp(str1, str2);
}