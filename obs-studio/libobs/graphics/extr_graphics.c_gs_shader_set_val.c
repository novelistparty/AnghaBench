#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  gs_sparam_t ;
struct TYPE_4__ {int /*<<< orphan*/  (* gs_shader_set_val ) (int /*<<< orphan*/ *,void const*,size_t) ;} ;
struct TYPE_5__ {TYPE_1__ exports; } ;
typedef  TYPE_2__ graphics_t ;

/* Variables and functions */
 int /*<<< orphan*/  gs_valid_p2 (char*,int /*<<< orphan*/ *,void const*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,void const*,size_t) ; 
 TYPE_2__* thread_graphics ; 

void gs_shader_set_val(gs_sparam_t *param, const void *val, size_t size)
{
	graphics_t *graphics = thread_graphics;

	if (!gs_valid_p2("gs_shader_set_val", param, val))
		return;

	graphics->exports.gs_shader_set_val(param, val, size);
}