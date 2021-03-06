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
typedef  int /*<<< orphan*/  mach_port_mscount_t ;
typedef  int /*<<< orphan*/  ipc_port_t ;

/* Variables and functions */
 int /*<<< orphan*/  mach_notify_no_senders (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
ipc_notify_no_senders(
	ipc_port_t		port,
	mach_port_mscount_t	mscount)
{
	(void)mach_notify_no_senders(port, mscount);
	/* send-once right consumed */
}