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
typedef  scalar_t__ u32 ;
struct rcar_dmac {scalar_t__ iomem; } ;

/* Variables and functions */
 scalar_t__ RCAR_DMAOR ; 
 int /*<<< orphan*/  writel (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  writew (scalar_t__,scalar_t__) ; 

__attribute__((used)) static void rcar_dmac_write(struct rcar_dmac *dmac, u32 reg, u32 data)
{
	if (reg == RCAR_DMAOR)
		writew(data, dmac->iomem + reg);
	else
		writel(data, dmac->iomem + reg);
}