#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  core; } ;
struct bgmac {TYPE_1__ bcma; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcma_core_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void bcma_bgmac_clk_enable(struct bgmac *bgmac, u32 flags)
{
	bcma_core_enable(bgmac->bcma.core, flags);
}