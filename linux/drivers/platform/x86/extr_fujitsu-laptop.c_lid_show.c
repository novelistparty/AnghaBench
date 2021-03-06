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
struct fujitsu_laptop {int flags_supported; int flags_state; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int FLAG_LID ; 
 struct fujitsu_laptop* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  sprintf (char*,char*) ; 

__attribute__((used)) static ssize_t lid_show(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	struct fujitsu_laptop *priv = dev_get_drvdata(dev);

	if (!(priv->flags_supported & FLAG_LID))
		return sprintf(buf, "unknown\n");
	if (priv->flags_state & FLAG_LID)
		return sprintf(buf, "open\n");
	else
		return sprintf(buf, "closed\n");
}