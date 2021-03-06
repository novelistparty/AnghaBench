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
typedef  int /*<<< orphan*/  uschar ;

/* Variables and functions */
 scalar_t__ isalnum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isalpha (int /*<<< orphan*/ ) ; 

int isclvar(const char *s)	/* is s of form var=something ? */
{
	const char *os = s;

	if (!isalpha((uschar) *s) && *s != '_')
		return 0;
	for ( ; *s; s++)
		if (!(isalnum((uschar) *s) || *s == '_'))
			break;
	return *s == '=' && s > os;
}