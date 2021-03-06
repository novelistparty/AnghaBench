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
struct spi_master {int dummy; } ;
struct mxs_ssp {int /*<<< orphan*/  clk; } ;
struct mxs_spi {struct mxs_ssp ssp; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int clk_prepare_enable (int /*<<< orphan*/ ) ; 
 struct spi_master* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int,int) ; 
 int pinctrl_pm_select_idle_state (struct device*) ; 
 struct mxs_spi* spi_master_get_devdata (struct spi_master*) ; 

__attribute__((used)) static int mxs_spi_runtime_suspend(struct device *dev)
{
	struct spi_master *master = dev_get_drvdata(dev);
	struct mxs_spi *spi = spi_master_get_devdata(master);
	struct mxs_ssp *ssp = &spi->ssp;
	int ret;

	clk_disable_unprepare(ssp->clk);

	ret = pinctrl_pm_select_idle_state(dev);
	if (ret) {
		int ret2 = clk_prepare_enable(ssp->clk);

		if (ret2)
			dev_warn(dev, "Failed to reenable clock after failing pinctrl request (pinctrl: %d, clk: %d)\n",
				 ret, ret2);
	}

	return ret;
}