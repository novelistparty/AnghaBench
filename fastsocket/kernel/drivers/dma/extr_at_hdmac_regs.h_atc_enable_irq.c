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
struct at_dma_chan {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  atc_setup_irq (struct at_dma_chan*,int) ; 

__attribute__((used)) static inline void atc_enable_irq(struct at_dma_chan *atchan)
{
	atc_setup_irq(atchan, 1);
}