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
struct brcmf_bus {int state; } ;
typedef  enum brcmf_bus_state { ____Placeholder_brcmf_bus_state } brcmf_bus_state ;

/* Variables and functions */

void
brcmf_bus_change_state(struct brcmf_bus *bus, enum brcmf_bus_state state)
{
	bus->state = state;
}