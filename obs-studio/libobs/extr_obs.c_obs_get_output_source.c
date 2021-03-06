#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  obs_source_t ;
struct TYPE_3__ {int /*<<< orphan*/  main_view; } ;
struct TYPE_4__ {TYPE_1__ data; } ;

/* Variables and functions */
 TYPE_2__* obs ; 
 int /*<<< orphan*/ * obs_view_get_source (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

obs_source_t *obs_get_output_source(uint32_t channel)
{
	if (!obs)
		return NULL;
	return obs_view_get_source(&obs->data.main_view, channel);
}