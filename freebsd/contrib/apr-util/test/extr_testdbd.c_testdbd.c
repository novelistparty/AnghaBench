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
typedef  int /*<<< orphan*/  abts_suite ;

/* Variables and functions */
 int /*<<< orphan*/ * ADD_SUITE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  abts_run_test (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  test_dbd_init ; 
 int /*<<< orphan*/  test_dbd_sqlite2 ; 
 int /*<<< orphan*/  test_dbd_sqlite3 ; 

abts_suite *testdbd(abts_suite *suite)
{
    suite = ADD_SUITE(suite);


    abts_run_test(suite, test_dbd_init, NULL);

#if APU_HAVE_SQLITE2
    abts_run_test(suite, test_dbd_sqlite2, NULL);
#endif

#if APU_HAVE_SQLITE3
    abts_run_test(suite, test_dbd_sqlite3, NULL);
#endif
    return suite;
}