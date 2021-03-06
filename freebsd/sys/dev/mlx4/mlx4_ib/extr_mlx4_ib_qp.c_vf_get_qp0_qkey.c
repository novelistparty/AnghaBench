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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int num_ports; int* qp0_proxy; int* qp0_tunnel; int /*<<< orphan*/ * qp0_qkey; } ;
struct mlx4_dev {TYPE_1__ caps; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static int vf_get_qp0_qkey(struct mlx4_dev *dev, int qpn, u32 *qkey)
{
	int i;
	for (i = 0; i < dev->caps.num_ports; i++) {
		if (qpn == dev->caps.qp0_proxy[i] ||
		    qpn == dev->caps.qp0_tunnel[i]) {
			*qkey = dev->caps.qp0_qkey[i];
			return 0;
		}
	}
	return -EINVAL;
}