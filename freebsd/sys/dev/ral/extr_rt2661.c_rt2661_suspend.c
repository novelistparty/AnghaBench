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
struct rt2661_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  rt2661_stop (struct rt2661_softc*) ; 

void
rt2661_suspend(void *xsc)
{
	struct rt2661_softc *sc = xsc;

	rt2661_stop(sc);
}