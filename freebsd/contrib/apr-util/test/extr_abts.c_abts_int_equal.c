#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ failed; } ;
typedef  TYPE_1__ abts_case ;

/* Variables and functions */
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int const,int const) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  update_status () ; 
 scalar_t__ verbose ; 

void abts_int_equal(abts_case *tc, const int expected, const int actual, int lineno)
{
    update_status();
    if (tc->failed) return;

    if (expected == actual) return;

    tc->failed = TRUE;
    if (verbose) {
        fprintf(stderr, "Line %d: expected <%d>, but saw <%d>\n", lineno, expected, actual);
        fflush(stderr);
    }
}