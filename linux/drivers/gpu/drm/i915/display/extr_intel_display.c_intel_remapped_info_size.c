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
struct intel_remapped_info {TYPE_1__* plane; } ;
struct TYPE_2__ {unsigned int width; unsigned int height; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 

unsigned int intel_remapped_info_size(const struct intel_remapped_info *rem_info)
{
	unsigned int size = 0;
	int i;

	for (i = 0 ; i < ARRAY_SIZE(rem_info->plane); i++)
		size += rem_info->plane[i].width * rem_info->plane[i].height;

	return size;
}