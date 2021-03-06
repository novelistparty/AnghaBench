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
struct dma_fifo {scalar_t__ open; scalar_t__ open_limit; } ;

/* Variables and functions */

__attribute__((used)) static inline bool dma_fifo_busy(struct dma_fifo *fifo)
{
	return fifo->open == fifo->open_limit;
}