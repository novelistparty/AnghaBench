#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {unsigned long count; int invalid; int /*<<< orphan*/ * sg; scalar_t__ active; } ;
typedef  TYPE_1__ dma_t ;

/* Variables and functions */
 TYPE_1__* dma_channel (unsigned int) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned int) ; 

void set_dma_count (unsigned int chan, unsigned long count)
{
	dma_t *dma = dma_channel(chan);

	if (dma->active)
		pr_err("dma%d: altering DMA count while DMA active\n", chan);

	dma->sg = NULL;
	dma->count = count;
	dma->invalid = 1;
}