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
struct soc_pcmcia_socket {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  board_pcmcia_power (int) ; 

__attribute__((used)) static void trizeps_pcmcia_socket_init(struct soc_pcmcia_socket *skt)
{
	/* default is on */
	board_pcmcia_power(0x9);
}