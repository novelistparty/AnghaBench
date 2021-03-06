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
struct amdgpu_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  iceland_ih_disable_interrupts (struct amdgpu_device*) ; 
 int /*<<< orphan*/  mdelay (int) ; 

__attribute__((used)) static void iceland_ih_irq_disable(struct amdgpu_device *adev)
{
	iceland_ih_disable_interrupts(adev);

	/* Wait and acknowledge irq */
	mdelay(1);
}