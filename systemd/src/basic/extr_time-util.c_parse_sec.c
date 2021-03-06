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
typedef  int /*<<< orphan*/  usec_t ;

/* Variables and functions */
 int /*<<< orphan*/  USEC_PER_SEC ; 
 int parse_time (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int parse_sec(const char *t, usec_t *usec) {
        return parse_time(t, usec, USEC_PER_SEC);
}