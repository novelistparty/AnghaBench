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
struct nvkm_engine {int dummy; } ;

/* Variables and functions */
 void* nvkm_sw (struct nvkm_engine*) ; 

__attribute__((used)) static void *
nvkm_sw_dtor(struct nvkm_engine *engine)
{
	return nvkm_sw(engine);
}