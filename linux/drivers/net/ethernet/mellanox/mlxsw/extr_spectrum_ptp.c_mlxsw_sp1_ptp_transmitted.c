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
typedef  int /*<<< orphan*/  u8 ;
struct sk_buff {int dummy; } ;
struct mlxsw_sp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlxsw_sp1_ptp_got_packet (struct mlxsw_sp*,struct sk_buff*,int /*<<< orphan*/ ,int) ; 

void mlxsw_sp1_ptp_transmitted(struct mlxsw_sp *mlxsw_sp,
			       struct sk_buff *skb, u8 local_port)
{
	mlxsw_sp1_ptp_got_packet(mlxsw_sp, skb, local_port, false);
}