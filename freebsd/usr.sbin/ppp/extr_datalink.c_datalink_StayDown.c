#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int tries; } ;
struct datalink {scalar_t__ stayonline; scalar_t__ reconnect_tries; TYPE_1__ dial; } ;

/* Variables and functions */

void
datalink_StayDown(struct datalink *dl)
{
  dl->dial.tries = -1;
  dl->reconnect_tries = 0;
  dl->stayonline = 0;
}