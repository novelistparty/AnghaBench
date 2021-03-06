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
struct uart_port {int dummy; } ;
struct serial_struct {scalar_t__ type; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ PORT_UART00 ; 

__attribute__((used)) static int serial_lpc32xx_verify_port(struct uart_port *port,
				      struct serial_struct *ser)
{
	int ret = 0;

	if (ser->type != PORT_UART00)
		ret = -EINVAL;

	return ret;
}