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
typedef  int /*<<< orphan*/  LPTSTR ;
typedef  int /*<<< orphan*/  INT ;

/* Variables and functions */
 int /*<<< orphan*/  ConErrPuts (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ConOutResPuts (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STRING_ECHO_HELP2 ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _T (char*) ; 
 int /*<<< orphan*/  _tcsncmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  debugstr_aw (int /*<<< orphan*/ ) ; 

INT CommandEchoerr (LPTSTR param)
{
    TRACE ("CommandEchoerr: '%s'\n", debugstr_aw(param));

    if (!_tcsncmp (param, _T("/?"), 2))
    {
        ConOutResPuts(STRING_ECHO_HELP2);
        return 0;
    }

    ConErrPuts (param);
    return 0;
}