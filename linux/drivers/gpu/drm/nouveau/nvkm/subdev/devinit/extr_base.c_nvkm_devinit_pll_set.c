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
struct nvkm_devinit {TYPE_1__* func; } ;
struct TYPE_2__ {int (* pll_set ) (struct nvkm_devinit*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (struct nvkm_devinit*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int
nvkm_devinit_pll_set(struct nvkm_devinit *init, u32 type, u32 khz)
{
	return init->func->pll_set(init, type, khz);
}