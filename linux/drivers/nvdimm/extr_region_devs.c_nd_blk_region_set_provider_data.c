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
struct nd_blk_region {void* blk_provider_data; } ;

/* Variables and functions */

void nd_blk_region_set_provider_data(struct nd_blk_region *ndbr, void *data)
{
	ndbr->blk_provider_data = data;
}