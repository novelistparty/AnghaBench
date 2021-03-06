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
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  WRITE_SPECIALREG (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  isb () ; 
 int /*<<< orphan*/  pmintenset_el1 ; 

__attribute__((used)) static __inline void
arm64_interrupt_enable(uint32_t pmc)
{
	uint32_t reg;

	reg = (1 << pmc);
	WRITE_SPECIALREG(pmintenset_el1, reg);

	isb();
}