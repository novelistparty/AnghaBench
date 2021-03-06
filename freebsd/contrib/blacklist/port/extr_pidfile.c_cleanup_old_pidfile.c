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
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pidfile_cleanup () ; 
 int /*<<< orphan*/ * pidfile_path ; 
 scalar_t__ strcmp (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static int
cleanup_old_pidfile(const char* path)
{
	if (pidfile_path != NULL) {
		if (strcmp(pidfile_path, path) != 0) {
			pidfile_cleanup();

			free(pidfile_path);
			pidfile_path = NULL;

			return 1;
		} else
			return 0;
	} else
		return 1;
}