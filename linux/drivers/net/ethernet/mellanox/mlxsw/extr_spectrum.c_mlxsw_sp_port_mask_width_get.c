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
typedef  int u8 ;

/* Variables and functions */
 int MLXSW_SP_PORT_MASK_WIDTH_1X ; 
 int MLXSW_SP_PORT_MASK_WIDTH_2X ; 
 int MLXSW_SP_PORT_MASK_WIDTH_4X ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 

__attribute__((used)) static u8 mlxsw_sp_port_mask_width_get(u8 width)
{
	switch (width) {
	case 1:
		return MLXSW_SP_PORT_MASK_WIDTH_1X;
	case 2:
		return MLXSW_SP_PORT_MASK_WIDTH_2X;
	case 4:
		return MLXSW_SP_PORT_MASK_WIDTH_4X;
	default:
		WARN_ON_ONCE(1);
		return 0;
	}
}