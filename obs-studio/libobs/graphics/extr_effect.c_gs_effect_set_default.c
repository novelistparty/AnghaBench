#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  num; int /*<<< orphan*/  array; } ;
struct TYPE_6__ {TYPE_1__ default_val; } ;
typedef  TYPE_2__ gs_eparam_t ;

/* Variables and functions */
 int /*<<< orphan*/  effect_setval_inline (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void gs_effect_set_default(gs_eparam_t *param)
{
	effect_setval_inline(param, param->default_val.array,
			     param->default_val.num);
}