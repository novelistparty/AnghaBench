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
struct nvkm_oclass {int dummy; } ;
struct nvkm_object {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct nvkm_control {struct nvkm_object object; struct nvkm_device* device; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct nvkm_control* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_control ; 
 int /*<<< orphan*/  nvkm_object_ctor (int /*<<< orphan*/ *,struct nvkm_oclass const*,struct nvkm_object*) ; 

__attribute__((used)) static int
nvkm_control_new(struct nvkm_device *device, const struct nvkm_oclass *oclass,
		 void *data, u32 size, struct nvkm_object **pobject)
{
	struct nvkm_control *ctrl;

	if (!(ctrl = kzalloc(sizeof(*ctrl), GFP_KERNEL)))
		return -ENOMEM;
	*pobject = &ctrl->object;
	ctrl->device = device;

	nvkm_object_ctor(&nvkm_control, oclass, &ctrl->object);
	return 0;
}