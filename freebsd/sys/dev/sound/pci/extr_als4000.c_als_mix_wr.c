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
typedef  int /*<<< orphan*/  u_int8_t ;
struct sc_info {int /*<<< orphan*/  sh; int /*<<< orphan*/  st; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALS_MIXER_DATA ; 
 int /*<<< orphan*/  ALS_MIXER_INDEX ; 
 int /*<<< orphan*/  bus_space_write_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
als_mix_wr(struct sc_info *sc, u_int8_t index, u_int8_t data)
{
	bus_space_write_1(sc->st, sc->sh, ALS_MIXER_INDEX, index);
	bus_space_write_1(sc->st, sc->sh, ALS_MIXER_DATA, data);
}