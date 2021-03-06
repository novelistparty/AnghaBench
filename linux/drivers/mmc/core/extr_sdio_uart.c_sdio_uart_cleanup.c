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
struct tty_struct {struct sdio_uart_port* driver_data; } ;
struct sdio_uart_port {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sdio_uart_port_put (struct sdio_uart_port*) ; 

__attribute__((used)) static void sdio_uart_cleanup(struct tty_struct *tty)
{
	struct sdio_uart_port *port = tty->driver_data;
	tty->driver_data = NULL;	/* Bug trap */
	sdio_uart_port_put(port);
}