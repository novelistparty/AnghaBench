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
struct sbc_softc {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_mtxunlock (int /*<<< orphan*/ ) ; 

void
sbc_unlock(struct sbc_softc *scp)
{
	snd_mtxunlock(scp->lock);
}