#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ dbcnt; } ;
struct TYPE_3__ {scalar_t__ dbcnt; } ;

/* Variables and functions */
 TYPE_2__ in ; 
 TYPE_1__ out ; 

void
def_close(void)
{
	/* Just update the count, everything is already in the buffer. */
	if (in.dbcnt)
		out.dbcnt = in.dbcnt;
}