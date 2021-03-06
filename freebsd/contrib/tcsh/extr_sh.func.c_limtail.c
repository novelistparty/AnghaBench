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
typedef  int /*<<< orphan*/  Char ;

/* Variables and functions */
 int /*<<< orphan*/  ERR_BADSCALE ; 
 int /*<<< orphan*/  stderror (int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ strtail (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static void
limtail(Char *cp, const char *str)
{
    if (strtail(cp, str))
	stderror(ERR_BADSCALE, str);
}