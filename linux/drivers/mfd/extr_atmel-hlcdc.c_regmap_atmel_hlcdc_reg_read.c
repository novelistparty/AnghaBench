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
struct atmel_hlcdc_regmap {scalar_t__ regs; } ;

/* Variables and functions */
 unsigned int readl (scalar_t__) ; 

__attribute__((used)) static int regmap_atmel_hlcdc_reg_read(void *context, unsigned int reg,
				       unsigned int *val)
{
	struct atmel_hlcdc_regmap *hregmap = context;

	*val = readl(hregmap->regs + reg);

	return 0;
}