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
struct arswitch_softc {int /*<<< orphan*/  callout_tick; } ;

/* Variables and functions */
 int /*<<< orphan*/  arswitch_miipollstat (struct arswitch_softc*) ; 
 int /*<<< orphan*/  callout_reset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void (*) (void*),struct arswitch_softc*) ; 
 int /*<<< orphan*/  hz ; 

__attribute__((used)) static void
arswitch_tick(void *arg)
{
	struct arswitch_softc *sc = arg;

	arswitch_miipollstat(sc);
	callout_reset(&sc->callout_tick, hz, arswitch_tick, sc);
}