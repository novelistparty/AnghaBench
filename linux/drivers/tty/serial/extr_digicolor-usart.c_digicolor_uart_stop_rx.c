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
typedef  int /*<<< orphan*/  u8 ;
struct uart_port {scalar_t__ membase; } ;

/* Variables and functions */
 scalar_t__ UA_INT_ENABLE ; 
 int /*<<< orphan*/  UA_INT_RX ; 
 int /*<<< orphan*/  readb_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writeb_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void digicolor_uart_stop_rx(struct uart_port *port)
{
	u8 int_enable = readb_relaxed(port->membase + UA_INT_ENABLE);

	int_enable &= ~UA_INT_RX;
	writeb_relaxed(int_enable, port->membase + UA_INT_ENABLE);
}