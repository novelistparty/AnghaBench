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
struct zip_error {int zip_err; int sys_err; } ;

/* Variables and functions */

void
_zip_error_set(struct zip_error *err, int ze, int se)
{
    if (err) {
	err->zip_err = ze;
	err->sys_err = se;
    }
}