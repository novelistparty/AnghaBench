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
struct uart_bas {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  quicc_setup (struct uart_bas*,int,int,int,int) ; 

__attribute__((used)) static void
quicc_init(struct uart_bas *bas, int baudrate, int databits, int stopbits,
    int parity)
{

	quicc_setup(bas, baudrate, databits, stopbits, parity);
}