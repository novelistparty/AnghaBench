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
struct vmci_transport_send_notify_data {int dummy; } ;
struct sock {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int
vmci_transport_notify_pkt_send_pre_enqueue(
				struct sock *sk,
				struct vmci_transport_send_notify_data *data)
{
	return 0; /* NOP for QState. */
}