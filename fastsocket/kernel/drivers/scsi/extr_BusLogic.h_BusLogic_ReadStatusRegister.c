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
struct BusLogic_HostAdapter {scalar_t__ IO_Address; } ;

/* Variables and functions */
 scalar_t__ BusLogic_StatusRegisterOffset ; 
 unsigned char inb (scalar_t__) ; 

__attribute__((used)) static inline unsigned char BusLogic_ReadStatusRegister(struct BusLogic_HostAdapter *HostAdapter)
{
	return inb(HostAdapter->IO_Address + BusLogic_StatusRegisterOffset);
}