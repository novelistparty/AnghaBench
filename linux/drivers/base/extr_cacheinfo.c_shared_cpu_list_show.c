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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  shared_cpumap_show_func (struct device*,int,char*) ; 

__attribute__((used)) static ssize_t shared_cpu_list_show(struct device *dev,
				    struct device_attribute *attr, char *buf)
{
	return shared_cpumap_show_func(dev, true, buf);
}