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

/* Variables and functions */
 int /*<<< orphan*/  inferior_ptid ; 
 int /*<<< orphan*/  null_ptid ; 
 scalar_t__ vx_running ; 
 int /*<<< orphan*/  xfree (scalar_t__) ; 

__attribute__((used)) static void
vx_proc_close (int quitting)
{
  inferior_ptid = null_ptid;	/* No longer have a process.  */
  if (vx_running)
    xfree (vx_running);
  vx_running = 0;
}