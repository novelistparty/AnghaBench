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
 scalar_t__ ENOENT ; 
 int FALSE ; 
 int TRUE ; 
 scalar_t__ errno ; 
 int mkdir (char const*,int) ; 
 int /*<<< orphan*/  xdiraccess (char const*) ; 

__attribute__((used)) static bool create_dir(const char *path)
{
	if (!xdiraccess(path)) {
		if (errno != ENOENT)
			return FALSE;

		if (mkdir(path, 0755) == -1)
			return FALSE;
	}

	return TRUE;
}