#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int mtu; } ;
struct aq_nic_s {TYPE_1__ aq_nic_cfg; } ;

/* Variables and functions */

int aq_nic_set_mtu(struct aq_nic_s *self, int new_mtu)
{
	self->aq_nic_cfg.mtu = new_mtu;

	return 0;
}