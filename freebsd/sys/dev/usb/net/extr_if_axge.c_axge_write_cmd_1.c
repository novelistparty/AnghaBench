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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct axge_softc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  axge_write_mem (struct axge_softc*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void
axge_write_cmd_1(struct axge_softc *sc, uint8_t cmd, uint16_t reg, uint8_t val)
{
	axge_write_mem(sc, cmd, 1, reg, &val, 1);
}