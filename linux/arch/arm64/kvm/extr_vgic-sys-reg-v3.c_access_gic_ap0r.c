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
struct sys_reg_params {int dummy; } ;
struct sys_reg_desc {int dummy; } ;
struct kvm_vcpu {int dummy; } ;

/* Variables and functions */
 int access_gic_aprn (struct kvm_vcpu*,struct sys_reg_params*,struct sys_reg_desc const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool access_gic_ap0r(struct kvm_vcpu *vcpu, struct sys_reg_params *p,
			    const struct sys_reg_desc *r)

{
	return access_gic_aprn(vcpu, p, r, 0);
}