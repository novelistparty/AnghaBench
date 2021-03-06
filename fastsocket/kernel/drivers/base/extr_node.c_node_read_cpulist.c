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
struct sysdev_attribute {int dummy; } ;
struct sys_device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  node_read_cpumap (struct sys_device*,int,char*) ; 

__attribute__((used)) static inline ssize_t node_read_cpulist(struct sys_device *dev,
				struct sysdev_attribute *attr, char *buf)
{
	return node_read_cpumap(dev, 1, buf);
}