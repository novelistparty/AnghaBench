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
typedef  int /*<<< orphan*/  u64 ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IA64_ALT_INST_TLB_VECTOR ; 
 int /*<<< orphan*/  inject_guest_interruption (struct kvm_vcpu*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_ifa_itir_iha (struct kvm_vcpu*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 

void alt_itlb(struct kvm_vcpu *vcpu, u64 vadr)
{
	set_ifa_itir_iha(vcpu, vadr, 1, 1, 0);
	inject_guest_interruption(vcpu, IA64_ALT_INST_TLB_VECTOR);
}