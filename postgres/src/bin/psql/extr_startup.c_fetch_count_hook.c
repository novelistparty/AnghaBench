#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  fetch_count; } ;

/* Variables and functions */
 int ParseVariableNum (char const*,char*,int /*<<< orphan*/ *) ; 
 TYPE_1__ pset ; 

__attribute__((used)) static bool
fetch_count_hook(const char *newval)
{
	return ParseVariableNum(newval, "FETCH_COUNT", &pset.fetch_count);
}