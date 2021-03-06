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
typedef  int /*<<< orphan*/  u32 ;
struct e1000_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUGFUNC (char*) ; 
 int /*<<< orphan*/  E1000_EXTCNF_CTRL ; 
 int /*<<< orphan*/  E1000_EXTCNF_CTRL_MDIO_SW_OWNERSHIP ; 
 int /*<<< orphan*/  E1000_READ_REG (struct e1000_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  E1000_WRITE_REG (struct e1000_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
e1000_put_hw_semaphore_82574(struct e1000_hw *hw)
{
	u32 extcnf_ctrl;

	DEBUGFUNC("e1000_put_hw_semaphore_82574");

	extcnf_ctrl = E1000_READ_REG(hw, E1000_EXTCNF_CTRL);
	extcnf_ctrl &= ~E1000_EXTCNF_CTRL_MDIO_SW_OWNERSHIP;
	E1000_WRITE_REG(hw, E1000_EXTCNF_CTRL, extcnf_ctrl);
}