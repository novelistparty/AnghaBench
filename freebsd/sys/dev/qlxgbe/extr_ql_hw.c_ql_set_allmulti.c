#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  mac_rcv_mode; } ;
struct TYPE_6__ {TYPE_1__ hw; } ;
typedef  TYPE_2__ qla_host_t ;

/* Variables and functions */
 int /*<<< orphan*/  Q8_MBX_MAC_ALL_MULTI_ENABLE ; 
 int qla_set_mac_rcv_mode (TYPE_2__*,int /*<<< orphan*/ ) ; 

int
ql_set_allmulti(qla_host_t *ha)
{
	int ret;

	ha->hw.mac_rcv_mode |= Q8_MBX_MAC_ALL_MULTI_ENABLE;
	ret = qla_set_mac_rcv_mode(ha, ha->hw.mac_rcv_mode);
	return (ret);
}