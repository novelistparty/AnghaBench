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
typedef  int u_int ;
struct vscphy_softc {int /*<<< orphan*/  mii_sc; } ;

/* Variables and functions */
 int PHY_READ (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline int
vscphy_read(struct vscphy_softc *sc, u_int reg)
{
	u_int val;

	val = PHY_READ(&sc->mii_sc, reg);
	return (val);
}