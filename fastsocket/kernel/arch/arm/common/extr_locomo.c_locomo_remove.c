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
struct locomo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __locomo_remove (struct locomo*) ; 
 struct locomo* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int locomo_remove(struct platform_device *dev)
{
	struct locomo *lchip = platform_get_drvdata(dev);

	if (lchip) {
		__locomo_remove(lchip);
		platform_set_drvdata(dev, NULL);
	}

	return 0;
}