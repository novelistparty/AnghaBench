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
struct uart_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SUNW_SETCONSINPUT_OBP ; 
 int /*<<< orphan*/  sbbc_serengeti_set_console_input (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
sbbc_uart_bus_detach(struct uart_softc *sc)
{

	/* Give back the console input. */
	sbbc_serengeti_set_console_input(SUNW_SETCONSINPUT_OBP);
	return (0);
}