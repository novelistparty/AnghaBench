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
struct xlnx_pr_decoupler_data {int /*<<< orphan*/  clk; } ;
struct platform_device {int dummy; } ;
struct fpga_bridge {struct xlnx_pr_decoupler_data* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fpga_bridge_unregister (struct fpga_bridge*) ; 
 struct fpga_bridge* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int xlnx_pr_decoupler_remove(struct platform_device *pdev)
{
	struct fpga_bridge *bridge = platform_get_drvdata(pdev);
	struct xlnx_pr_decoupler_data *p = bridge->priv;

	fpga_bridge_unregister(bridge);

	clk_unprepare(p->clk);

	return 0;
}