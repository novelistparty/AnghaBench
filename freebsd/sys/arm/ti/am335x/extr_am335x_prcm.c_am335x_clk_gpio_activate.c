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
struct ti_clock_dev {int /*<<< orphan*/  id; } ;
struct am335x_prcm_softc {int dummy; } ;
struct am335x_clk_details {int /*<<< orphan*/  clkctrl_reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  DELAY (int) ; 
 int ENXIO ; 
 struct am335x_clk_details* am335x_clk_details (int /*<<< orphan*/ ) ; 
 struct am335x_prcm_softc* am335x_prcm_sc ; 
 int prcm_read_4 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prcm_write_4 (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int
am335x_clk_gpio_activate(struct ti_clock_dev *clkdev)
{
	struct am335x_prcm_softc *sc = am335x_prcm_sc;
	struct am335x_clk_details* clk_details;

	if (sc == NULL)
		return ENXIO;

	clk_details = am335x_clk_details(clkdev->id);

	if (clk_details == NULL)
		return (ENXIO);

	/* set *_CLKCTRL register MODULEMODE[1:0] to enable(2) */
	/* set *_CLKCTRL register OPTFCLKEN_GPIO_1_G DBCLK[18] to FCLK_EN(1) */
	prcm_write_4(clk_details->clkctrl_reg, 2 | (1 << 18));
	while ((prcm_read_4(clk_details->clkctrl_reg) &
	    (3 | (1 << 18) )) != (2 | (1 << 18)))
		DELAY(10);

	return (0);
}