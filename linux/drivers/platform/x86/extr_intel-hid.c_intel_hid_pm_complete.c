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
struct intel_hid_priv {int wakeup_mode; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct intel_hid_priv* dev_get_drvdata (struct device*) ; 

__attribute__((used)) static void intel_hid_pm_complete(struct device *device)
{
	struct intel_hid_priv *priv = dev_get_drvdata(device);

	priv->wakeup_mode = false;
}