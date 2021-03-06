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
struct fdc_data {int /*<<< orphan*/ * ioff; int /*<<< orphan*/ * ioh; int /*<<< orphan*/  iot; } ;

/* Variables and functions */
 int /*<<< orphan*/  bus_space_write_1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
fdregwr(struct fdc_data *fdc, int reg, uint8_t v)
{

	bus_space_write_1(fdc->iot, fdc->ioh[reg], fdc->ioff[reg], v);
}