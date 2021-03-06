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
typedef  scalar_t__ time_t ;
typedef  int suseconds_t ;
struct timeval {int tv_usec; scalar_t__ tv_sec; } ;
typedef  int UINT16 ;

/* Variables and functions */
 int tvtohz (struct timeval*) ; 

__attribute__((used)) static int
timeout2hz(UINT16 Timeout)
{
	struct timeval		tv;

	tv.tv_sec = (time_t)(Timeout / 1000);
	tv.tv_usec = (suseconds_t)(Timeout % 1000) * 1000;

	return (tvtohz(&tv));
}