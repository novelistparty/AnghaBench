#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* shared; } ;
struct kvm_vcpu {TYPE_2__ arch; } ;
struct TYPE_7__ {int features; int /*<<< orphan*/  mas6; int /*<<< orphan*/  mas4; int /*<<< orphan*/  mas7_3; int /*<<< orphan*/  mas2; int /*<<< orphan*/  mas1; int /*<<< orphan*/  mas0; } ;
struct TYPE_8__ {TYPE_3__ e; } ;
struct kvm_sregs {TYPE_4__ u; } ;
struct TYPE_5__ {int /*<<< orphan*/  mas6; int /*<<< orphan*/  mas4; int /*<<< orphan*/  mas7_3; int /*<<< orphan*/  mas2; int /*<<< orphan*/  mas1; int /*<<< orphan*/  mas0; } ;

/* Variables and functions */
 int KVM_SREGS_E_ARCH206_MMU ; 

int kvmppc_set_sregs_e500_tlb(struct kvm_vcpu *vcpu, struct kvm_sregs *sregs)
{
	if (sregs->u.e.features & KVM_SREGS_E_ARCH206_MMU) {
		vcpu->arch.shared->mas0 = sregs->u.e.mas0;
		vcpu->arch.shared->mas1 = sregs->u.e.mas1;
		vcpu->arch.shared->mas2 = sregs->u.e.mas2;
		vcpu->arch.shared->mas7_3 = sregs->u.e.mas7_3;
		vcpu->arch.shared->mas4 = sregs->u.e.mas4;
		vcpu->arch.shared->mas6 = sregs->u.e.mas6;
	}

	return 0;
}