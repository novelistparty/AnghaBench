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
struct kobj_uevent_env {int dummy; } ;
struct device {int dummy; } ;
struct apr_device {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ENODEV ; 
 int add_uevent_var (struct kobj_uevent_env*,char*,int /*<<< orphan*/ ) ; 
 int of_device_uevent_modalias (struct device*,struct kobj_uevent_env*) ; 
 struct apr_device* to_apr_device (struct device*) ; 

__attribute__((used)) static int apr_uevent(struct device *dev, struct kobj_uevent_env *env)
{
	struct apr_device *adev = to_apr_device(dev);
	int ret;

	ret = of_device_uevent_modalias(dev, env);
	if (ret != -ENODEV)
		return ret;

	return add_uevent_var(env, "MODALIAS=apr:%s", adev->name);
}