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
struct device {int dummy; } ;

/* Variables and functions */
 int pcmcia_socket_dev_suspend (struct device*) ; 

__attribute__((used)) static int pxa2xx_drv_pcmcia_suspend(struct device *dev)
{
	return pcmcia_socket_dev_suspend(dev);
}