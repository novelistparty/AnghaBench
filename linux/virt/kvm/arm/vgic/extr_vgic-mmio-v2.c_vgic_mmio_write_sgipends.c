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
struct vgic_irq {unsigned long source; int pending_latch; int /*<<< orphan*/  irq_lock; } ;
struct kvm_vcpu {int /*<<< orphan*/  kvm; } ;
typedef  int gpa_t ;

/* Variables and functions */
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct vgic_irq* vgic_get_irq (int /*<<< orphan*/ ,struct kvm_vcpu*,int) ; 
 int /*<<< orphan*/  vgic_put_irq (int /*<<< orphan*/ ,struct vgic_irq*) ; 
 int /*<<< orphan*/  vgic_queue_irq_unlock (int /*<<< orphan*/ ,struct vgic_irq*,unsigned long) ; 

__attribute__((used)) static void vgic_mmio_write_sgipends(struct kvm_vcpu *vcpu,
				     gpa_t addr, unsigned int len,
				     unsigned long val)
{
	u32 intid = addr & 0x0f;
	int i;
	unsigned long flags;

	for (i = 0; i < len; i++) {
		struct vgic_irq *irq = vgic_get_irq(vcpu->kvm, vcpu, intid + i);

		raw_spin_lock_irqsave(&irq->irq_lock, flags);

		irq->source |= (val >> (i * 8)) & 0xff;

		if (irq->source) {
			irq->pending_latch = true;
			vgic_queue_irq_unlock(vcpu->kvm, irq, flags);
		} else {
			raw_spin_unlock_irqrestore(&irq->irq_lock, flags);
		}
		vgic_put_irq(vcpu->kvm, irq);
	}
}