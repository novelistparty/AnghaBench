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
 scalar_t__ isprint (char) ; 
 scalar_t__ strchr (char*,char) ; 

__attribute__((used)) static int isstring(char c)
{
	return (isprint(c)
		|| (c == '\0')
		|| strchr("\a\b\t\n\v\f\r", c));
}