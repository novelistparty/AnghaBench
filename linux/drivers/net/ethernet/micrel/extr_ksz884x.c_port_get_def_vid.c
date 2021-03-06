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
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct ksz_hw {scalar_t__ io; } ;

/* Variables and functions */
 scalar_t__ KS8842_PORT_CTRL_VID_OFFSET ; 
 int /*<<< orphan*/  PORT_CTRL_ADDR (int,scalar_t__) ; 
 int /*<<< orphan*/  readw (scalar_t__) ; 

__attribute__((used)) static void port_get_def_vid(struct ksz_hw *hw, int port, u16 *vid)
{
	u32 addr;

	PORT_CTRL_ADDR(port, addr);
	addr += KS8842_PORT_CTRL_VID_OFFSET;
	*vid = readw(hw->io + addr);
}