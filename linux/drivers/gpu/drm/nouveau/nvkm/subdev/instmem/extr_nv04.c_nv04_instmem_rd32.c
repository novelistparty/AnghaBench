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
typedef  scalar_t__ u32 ;
struct TYPE_2__ {int /*<<< orphan*/  device; } ;
struct nvkm_instmem {TYPE_1__ subdev; } ;

/* Variables and functions */
 scalar_t__ nvkm_rd32 (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static u32
nv04_instmem_rd32(struct nvkm_instmem *imem, u32 addr)
{
	return nvkm_rd32(imem->subdev.device, 0x700000 + addr);
}