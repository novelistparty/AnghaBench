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
typedef  int /*<<< orphan*/  intmax_t ;
typedef  scalar_t__ int64_t ;
typedef  int /*<<< orphan*/  UT_string ;

/* Variables and functions */
 int /*<<< orphan*/  utstring_printf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
ucl_utstring_append_int (int64_t val, void *ud)
{
	UT_string *buf = ud;

	utstring_printf (buf, "%jd", (intmax_t)val);
	return 0;
}