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
typedef  int u32 ;
struct ixgbe_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUGFUNC (char*) ; 
 int /*<<< orphan*/  IXGBE_EEC_BY_MAC (struct ixgbe_hw*) ; 
 int IXGBE_EEC_SK ; 
 int /*<<< orphan*/  IXGBE_WRITE_FLUSH (struct ixgbe_hw*) ; 
 int /*<<< orphan*/  IXGBE_WRITE_REG (struct ixgbe_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usec_delay (int) ; 

__attribute__((used)) static void ixgbe_raise_eeprom_clk(struct ixgbe_hw *hw, u32 *eec)
{
	DEBUGFUNC("ixgbe_raise_eeprom_clk");

	/*
	 * Raise the clock input to the EEPROM
	 * (setting the SK bit), then delay
	 */
	*eec = *eec | IXGBE_EEC_SK;
	IXGBE_WRITE_REG(hw, IXGBE_EEC_BY_MAC(hw), *eec);
	IXGBE_WRITE_FLUSH(hw);
	usec_delay(1);
}