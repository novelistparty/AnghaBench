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
struct muge_softc {int /*<<< orphan*/  sc_ue; } ;
struct mii_data {int /*<<< orphan*/  mii_media_status; int /*<<< orphan*/  mii_media_active; } ;
struct ifnet {struct muge_softc* if_softc; } ;
struct ifmediareq {int /*<<< orphan*/  ifm_status; int /*<<< orphan*/  ifm_active; } ;

/* Variables and functions */
 int /*<<< orphan*/  MUGE_LOCK (struct muge_softc*) ; 
 int /*<<< orphan*/  MUGE_UNLOCK (struct muge_softc*) ; 
 int /*<<< orphan*/  mii_pollstat (struct mii_data*) ; 
 struct mii_data* uether_getmii (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
muge_ifmedia_sts(struct ifnet *ifp, struct ifmediareq *ifmr)
{
	struct muge_softc *sc = ifp->if_softc;
	struct mii_data *mii = uether_getmii(&sc->sc_ue);

	MUGE_LOCK(sc);
	mii_pollstat(mii);
	ifmr->ifm_active = mii->mii_media_active;
	ifmr->ifm_status = mii->mii_media_status;
	MUGE_UNLOCK(sc);
}