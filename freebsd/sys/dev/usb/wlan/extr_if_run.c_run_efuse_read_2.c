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
typedef  int /*<<< orphan*/  uint16_t ;
struct run_softc {int dummy; } ;

/* Variables and functions */
 int run_efuse_read (struct run_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int
run_efuse_read_2(struct run_softc *sc, uint16_t addr, uint16_t *val)
{
	return (run_efuse_read(sc, addr, val, 2));
}