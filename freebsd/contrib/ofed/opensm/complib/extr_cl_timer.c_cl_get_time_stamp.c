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
typedef  int uint64_t ;
struct timeval {scalar_t__ tv_usec; scalar_t__ tv_sec; } ;

/* Variables and functions */
 int /*<<< orphan*/  gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 

uint64_t cl_get_time_stamp(void)
{
	uint64_t tstamp;
	struct timeval tv;

	gettimeofday(&tv, NULL);

	/* Convert the time of day into a microsecond timestamp. */
	tstamp = ((uint64_t) tv.tv_sec * 1000000) + (uint64_t) tv.tv_usec;

	return (tstamp);
}