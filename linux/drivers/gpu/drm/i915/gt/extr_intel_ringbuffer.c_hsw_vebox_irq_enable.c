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
struct intel_engine_cs {int /*<<< orphan*/  irq_enable_mask; int /*<<< orphan*/  gt; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENGINE_POSTING_READ (struct intel_engine_cs*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENGINE_WRITE (struct intel_engine_cs*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RING_IMR ; 
 int /*<<< orphan*/  gen6_gt_pm_unmask_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
hsw_vebox_irq_enable(struct intel_engine_cs *engine)
{
	ENGINE_WRITE(engine, RING_IMR, ~engine->irq_enable_mask);

	/* Flush/delay to ensure the RING_IMR is active before the GT IMR */
	ENGINE_POSTING_READ(engine, RING_IMR);

	gen6_gt_pm_unmask_irq(engine->gt, engine->irq_enable_mask);
}