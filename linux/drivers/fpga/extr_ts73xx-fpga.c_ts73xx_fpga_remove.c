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
struct platform_device {int dummy; } ;
struct fpga_manager {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  fpga_mgr_unregister (struct fpga_manager*) ; 
 struct fpga_manager* platform_get_drvdata (struct platform_device*) ; 

__attribute__((used)) static int ts73xx_fpga_remove(struct platform_device *pdev)
{
	struct fpga_manager *mgr = platform_get_drvdata(pdev);

	fpga_mgr_unregister(mgr);

	return 0;
}