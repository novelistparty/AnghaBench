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
struct bfa_ioim_s {int /*<<< orphan*/  start_time; } ;

/* Variables and functions */
 int /*<<< orphan*/  jiffies ; 

void
bfa_ioim_profile_start(struct bfa_ioim_s *ioim)
{
	ioim->start_time = jiffies;
}