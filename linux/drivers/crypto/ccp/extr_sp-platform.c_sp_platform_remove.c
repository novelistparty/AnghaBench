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
struct sp_device {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;

/* Variables and functions */
 struct sp_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_notice (struct device*,char*) ; 
 int /*<<< orphan*/  sp_destroy (struct sp_device*) ; 

__attribute__((used)) static int sp_platform_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sp_device *sp = dev_get_drvdata(dev);

	sp_destroy(sp);

	dev_notice(dev, "disabled\n");

	return 0;
}