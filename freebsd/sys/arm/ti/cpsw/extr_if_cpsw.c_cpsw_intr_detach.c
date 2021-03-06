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
struct cpsw_softc {scalar_t__* ih_cookie; int /*<<< orphan*/ * irq_res; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int CPSW_INTR_COUNT ; 
 int /*<<< orphan*/  bus_teardown_intr (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void
cpsw_intr_detach(struct cpsw_softc *sc)
{
	int i;

	for (i = 0; i < CPSW_INTR_COUNT; i++) {
		if (sc->ih_cookie[i]) {
			bus_teardown_intr(sc->dev, sc->irq_res[i],
			    sc->ih_cookie[i]);
		}
	}
}