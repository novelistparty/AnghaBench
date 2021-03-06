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
typedef  int /*<<< orphan*/  intl_error ;

/* Variables and functions */
 int /*<<< orphan*/  intl_error_reset (int /*<<< orphan*/ *) ; 

void intl_errors_reset( intl_error* err )
{
	if(err) {
		intl_error_reset( err );
	}
	intl_error_reset( NULL );
}