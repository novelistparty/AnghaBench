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
 int FALSE ; 
 int TRUE ; 

__attribute__((used)) static int Devices_IsValidForFilename(char ch)
{
	if ((ch >= 'A' && ch <= 'Z')
	 || (ch >= 'a' && ch <= 'z')
	 || (ch >= '0' && ch <= '9'))
		return TRUE;
	switch (ch) {
	case '!':
	case '#':
	case '$':
	case '&':
	case '\'':
	case '(':
	case ')':
	case '*':
	case '-':
	case '.':
	case '?':
	case '@':
	case '_':
		return TRUE;
	default:
		return FALSE;
	}
}