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
struct serial_info {scalar_t__ multi; } ;
struct pcmcia_device {int /*<<< orphan*/  config_flags; struct serial_info* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  CONF_ENABLE_ESR ; 

__attribute__((used)) static void quirk_config_socket(struct pcmcia_device *link)
{
	struct serial_info *info = link->priv;

	if (info->multi)
		link->config_flags |= CONF_ENABLE_ESR;
}