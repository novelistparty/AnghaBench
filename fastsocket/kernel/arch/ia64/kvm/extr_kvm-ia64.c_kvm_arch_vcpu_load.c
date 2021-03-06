#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ ht_active; } ;
struct kvm_vcpu {int cpu; TYPE_1__ arch; } ;

/* Variables and functions */
 int /*<<< orphan*/  kvm_migrate_hlt_timer (struct kvm_vcpu*) ; 

void kvm_arch_vcpu_load(struct kvm_vcpu *vcpu, int cpu)
{
	if (cpu != vcpu->cpu) {
		vcpu->cpu = cpu;
		if (vcpu->arch.ht_active)
			kvm_migrate_hlt_timer(vcpu);
	}
}