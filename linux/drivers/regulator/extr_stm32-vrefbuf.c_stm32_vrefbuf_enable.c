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
typedef  int u32 ;
struct stm32_vrefbuf {int /*<<< orphan*/  dev; scalar_t__ base; } ;
struct regulator_dev {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int STM32_ENVR ; 
 int STM32_HIZ ; 
 scalar_t__ STM32_VREFBUF_CSR ; 
 int STM32_VRR ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int pm_runtime_get_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_mark_last_busy (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_put_autosuspend (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (int /*<<< orphan*/ ) ; 
 struct stm32_vrefbuf* rdev_get_drvdata (struct regulator_dev*) ; 
 int readl_poll_timeout (scalar_t__,int,int,int,int) ; 
 int readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static int stm32_vrefbuf_enable(struct regulator_dev *rdev)
{
	struct stm32_vrefbuf *priv = rdev_get_drvdata(rdev);
	u32 val;
	int ret;

	ret = pm_runtime_get_sync(priv->dev);
	if (ret < 0) {
		pm_runtime_put_noidle(priv->dev);
		return ret;
	}

	val = readl_relaxed(priv->base + STM32_VREFBUF_CSR);
	val = (val & ~STM32_HIZ) | STM32_ENVR;
	writel_relaxed(val, priv->base + STM32_VREFBUF_CSR);

	/*
	 * Vrefbuf startup time depends on external capacitor: wait here for
	 * VRR to be set. That means output has reached expected value.
	 * ~650us sleep should be enough for caps up to 1.5uF. Use 10ms as
	 * arbitrary timeout.
	 */
	ret = readl_poll_timeout(priv->base + STM32_VREFBUF_CSR, val,
				 val & STM32_VRR, 650, 10000);
	if (ret) {
		dev_err(&rdev->dev, "stm32 vrefbuf timed out!\n");
		val = readl_relaxed(priv->base + STM32_VREFBUF_CSR);
		val = (val & ~STM32_ENVR) | STM32_HIZ;
		writel_relaxed(val, priv->base + STM32_VREFBUF_CSR);
	}

	pm_runtime_mark_last_busy(priv->dev);
	pm_runtime_put_autosuspend(priv->dev);

	return ret;
}