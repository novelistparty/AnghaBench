#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* sie_block; } ;
struct kvm_vcpu {TYPE_2__ arch; } ;
struct TYPE_3__ {int /*<<< orphan*/  cpuflags; } ;

/* Variables and functions */
 int CPUSTAT_STOP_INT ; 
 int atomic_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int __cpu_is_stopped(struct kvm_vcpu *vcpu)
{
	return atomic_read(&vcpu->arch.sie_block->cpuflags) & CPUSTAT_STOP_INT;
}