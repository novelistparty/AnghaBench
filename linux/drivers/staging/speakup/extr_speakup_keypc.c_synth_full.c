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
 scalar_t__ UART_RX ; 
 int inb_p (scalar_t__) ; 
 scalar_t__ synth_port ; 

__attribute__((used)) static inline bool synth_full(void)
{
	return (inb_p(synth_port + UART_RX) & 0x80) == 0;
}