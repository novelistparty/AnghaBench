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
struct meson_pwm {int /*<<< orphan*/  chip; } ;

/* Variables and functions */
 struct meson_pwm* platform_get_drvdata (struct platform_device*) ; 
 int pwmchip_remove (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int meson_pwm_remove(struct platform_device *pdev)
{
	struct meson_pwm *meson = platform_get_drvdata(pdev);

	return pwmchip_remove(&meson->chip);
}