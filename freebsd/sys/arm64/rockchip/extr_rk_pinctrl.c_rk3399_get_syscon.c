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
typedef  int uint32_t ;
struct syscon {int dummy; } ;
struct rk_pinctrl_softc {struct syscon* grf; struct syscon* pmu; } ;

/* Variables and functions */

__attribute__((used)) static struct syscon *
rk3399_get_syscon(struct rk_pinctrl_softc *sc, uint32_t bank)
{
	if (bank < 2)
		return (sc->pmu);

	return (sc->grf);
}