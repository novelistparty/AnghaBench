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
typedef  scalar_t__ u8 ;
typedef  int u16 ;
struct skge_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  xm_write16 (struct skge_hw const*,int,int,int) ; 

__attribute__((used)) static inline void xm_outhash(const struct skge_hw *hw, int port, int reg,
				   const u8 *hash)
{
	xm_write16(hw, port, reg,   (u16)hash[0] | ((u16)hash[1] << 8));
	xm_write16(hw, port, reg+2, (u16)hash[2] | ((u16)hash[3] << 8));
	xm_write16(hw, port, reg+4, (u16)hash[4] | ((u16)hash[5] << 8));
	xm_write16(hw, port, reg+6, (u16)hash[6] | ((u16)hash[7] << 8));
}