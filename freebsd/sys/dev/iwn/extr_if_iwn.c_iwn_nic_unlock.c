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
struct iwn_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IWN_CLRBITS (struct iwn_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IWN_GP_CNTRL ; 
 int /*<<< orphan*/  IWN_GP_CNTRL_MAC_ACCESS_REQ ; 

__attribute__((used)) static __inline void
iwn_nic_unlock(struct iwn_softc *sc)
{
	IWN_CLRBITS(sc, IWN_GP_CNTRL, IWN_GP_CNTRL_MAC_ACCESS_REQ);
}