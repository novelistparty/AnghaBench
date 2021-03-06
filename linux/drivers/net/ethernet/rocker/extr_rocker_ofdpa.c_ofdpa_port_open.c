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
struct rocker_port {struct ofdpa_port* wpriv; } ;
struct ofdpa_port {int dummy; } ;

/* Variables and functions */
 int ofdpa_port_fwd_enable (struct ofdpa_port*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ofdpa_port_open(struct rocker_port *rocker_port)
{
	struct ofdpa_port *ofdpa_port = rocker_port->wpriv;

	return ofdpa_port_fwd_enable(ofdpa_port, 0);
}