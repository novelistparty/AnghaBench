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
typedef  int /*<<< orphan*/  DestReceiver ;

/* Variables and functions */
 int /*<<< orphan*/  ShowAllGUCConfig (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ShowGUCConfigOption (char const*,int /*<<< orphan*/ *) ; 
 scalar_t__ guc_name_compare (char const*,char*) ; 

void
GetPGVariable(const char *name, DestReceiver *dest)
{
	if (guc_name_compare(name, "all") == 0)
		ShowAllGUCConfig(dest);
	else
		ShowGUCConfigOption(name, dest);
}