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
struct csa_midi_softc {int /*<<< orphan*/  mpu; int /*<<< orphan*/  (* mpu_intr ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
csamidi_midi_intr(void *arg)
{
	struct csa_midi_softc *scp = (struct csa_midi_softc *)arg;

	if (scp->mpu_intr)
		(scp->mpu_intr)(scp->mpu);
}