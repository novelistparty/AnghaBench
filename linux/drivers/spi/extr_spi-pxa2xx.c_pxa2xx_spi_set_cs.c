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
struct spi_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cs_assert (struct spi_device*) ; 
 int /*<<< orphan*/  cs_deassert (struct spi_device*) ; 

__attribute__((used)) static void pxa2xx_spi_set_cs(struct spi_device *spi, bool level)
{
	if (level)
		cs_deassert(spi);
	else
		cs_assert(spi);
}