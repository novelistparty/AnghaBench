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
struct pppThroughput {long long OctetsOut; int /*<<< orphan*/  PacketsOut; } ;

/* Variables and functions */

void
throughput_addout(struct pppThroughput *t, long long n)
{
  t->OctetsOut += n;
  t->PacketsOut++;
}