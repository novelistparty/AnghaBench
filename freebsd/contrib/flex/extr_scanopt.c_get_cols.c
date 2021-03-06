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
 scalar_t__ COLS ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  endwin () ; 
 char* getenv (char*) ; 
 int /*<<< orphan*/  initscr () ; 

__attribute__((used)) static int get_cols ()
{
	char   *env;
	int     cols = 80;	/* default */

#ifdef HAVE_NCURSES_H
	initscr ();
	endwin ();
	if (COLS > 0)
		return COLS;
#endif

	if ((env = getenv ("COLUMNS")) != NULL)
		cols = atoi (env);

	return cols;
}