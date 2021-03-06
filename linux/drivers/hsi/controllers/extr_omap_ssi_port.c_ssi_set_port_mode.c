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
typedef  int /*<<< orphan*/  u32 ;
struct omap_ssi_port {scalar_t__ ssr_base; scalar_t__ sst_base; } ;

/* Variables and functions */
 scalar_t__ SSI_SSR_MODE_REG ; 
 scalar_t__ SSI_SST_MODE_REG ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int ssi_set_port_mode(struct omap_ssi_port *omap_port, u32 mode)
{
	writel(mode, omap_port->sst_base + SSI_SST_MODE_REG);
	writel(mode, omap_port->ssr_base + SSI_SSR_MODE_REG);
	/* OCP barrier */
	mode = readl(omap_port->ssr_base + SSI_SSR_MODE_REG);

	return 0;
}