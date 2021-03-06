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
struct timeval {int /*<<< orphan*/  tv_usec; int /*<<< orphan*/  tv_sec; } ;
typedef  int /*<<< orphan*/  clock_usec_t ;
typedef  int /*<<< orphan*/  clock_sec_t ;

/* Variables and functions */
 int /*<<< orphan*/  clock_get_calendar_microtime (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void
microtime(
	struct timeval	*tvp)
{
	clock_sec_t		tv_sec;
	clock_usec_t	tv_usec;

	clock_get_calendar_microtime(&tv_sec, &tv_usec);

	tvp->tv_sec = tv_sec;
	tvp->tv_usec = tv_usec;
}