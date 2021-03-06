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
struct pcap_chip {int msr; int /*<<< orphan*/  msr_work; int /*<<< orphan*/  workqueue; } ;

/* Variables and functions */
 struct pcap_chip* get_irq_chip_data (unsigned int) ; 
 int irq_to_pcap (struct pcap_chip*,unsigned int) ; 
 int /*<<< orphan*/  queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void pcap_unmask_irq(unsigned int irq)
{
	struct pcap_chip *pcap = get_irq_chip_data(irq);

	pcap->msr &= ~(1 << irq_to_pcap(pcap, irq));
	queue_work(pcap->workqueue, &pcap->msr_work);
}