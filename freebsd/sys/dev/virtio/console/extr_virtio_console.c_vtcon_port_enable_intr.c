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
struct vtcon_port {int /*<<< orphan*/  vtcport_invq; } ;

/* Variables and functions */
 int /*<<< orphan*/  virtqueue_enable_intr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
vtcon_port_enable_intr(struct vtcon_port *port)
{

	/*
	 * NOTE: The out virtqueue is always polled, so its interrupt
	 * kept disabled.
	 */
	virtqueue_enable_intr(port->vtcport_invq);
}