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
typedef  int /*<<< orphan*/  uint32_t ;
struct omap_tll_softc {int /*<<< orphan*/  tll_mem_res; } ;
typedef  int /*<<< orphan*/  bus_size_t ;

/* Variables and functions */
 int /*<<< orphan*/  bus_read_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline uint32_t
omap_tll_read_4(struct omap_tll_softc *sc, bus_size_t off)
{
	return bus_read_4(sc->tll_mem_res, off);
}