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
struct dsi_data {int is_enabled; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct dsi_data* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  smp_wmb () ; 

__attribute__((used)) static int dsi_runtime_resume(struct device *dev)
{
	struct dsi_data *dsi = dev_get_drvdata(dev);

	dsi->is_enabled = true;
	/* ensure the irq handler sees the is_enabled value */
	smp_wmb();

	return 0;
}