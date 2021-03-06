#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  size_t u32 ;
struct nvkm_gpio {int dummy; } ;
struct TYPE_8__ {TYPE_3__* fb; } ;
struct gt215_ramfuc {TYPE_4__ base; } ;
struct dcb_gpio_func {int line; int* log; } ;
struct TYPE_6__ {TYPE_1__* device; } ;
struct TYPE_7__ {TYPE_2__ subdev; } ;
struct TYPE_5__ {struct nvkm_gpio* gpio; } ;

/* Variables and functions */
 int /*<<< orphan*/  DCB_GPIO_UNUSED ; 
 int nvkm_gpio_find (struct nvkm_gpio*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dcb_gpio_func*) ; 
 size_t nvkm_gpio_get (struct nvkm_gpio*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ram_mask (struct gt215_ramfuc*,struct nvkm_gpio,int,size_t) ; 
 int /*<<< orphan*/  ram_nsec (struct gt215_ramfuc*,int) ; 
 size_t ram_rd32 (struct gt215_ramfuc*,struct nvkm_gpio) ; 

__attribute__((used)) static void
gt215_ram_gpio(struct gt215_ramfuc *fuc, u8 tag, u32 val)
{
	struct nvkm_gpio *gpio = fuc->base.fb->subdev.device->gpio;
	struct dcb_gpio_func func;
	u32 reg, sh, gpio_val;
	int ret;

	if (nvkm_gpio_get(gpio, 0, tag, DCB_GPIO_UNUSED) != val) {
		ret = nvkm_gpio_find(gpio, 0, tag, DCB_GPIO_UNUSED, &func);
		if (ret)
			return;

		reg = func.line >> 3;
		sh = (func.line & 0x7) << 2;
		gpio_val = ram_rd32(fuc, gpio[reg]);
		if (gpio_val & (8 << sh))
			val = !val;
		if (!(func.log[1] & 1))
			val = !val;

		ram_mask(fuc, gpio[reg], (0x3 << sh), ((val | 0x2) << sh));
		ram_nsec(fuc, 20000);
	}
}