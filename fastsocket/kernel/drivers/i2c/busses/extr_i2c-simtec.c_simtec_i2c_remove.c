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
struct simtec_i2c_data {struct simtec_i2c_data* ioarea; int /*<<< orphan*/  reg; int /*<<< orphan*/  adap; } ;
struct platform_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct simtec_i2c_data*) ; 
 struct simtec_i2c_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  release_resource (struct simtec_i2c_data*) ; 

__attribute__((used)) static int simtec_i2c_remove(struct platform_device *dev)
{
	struct simtec_i2c_data *pd = platform_get_drvdata(dev);

	i2c_del_adapter(&pd->adap);

	iounmap(pd->reg);
	release_resource(pd->ioarea);
	kfree(pd->ioarea);
	kfree(pd);

	return 0;
}