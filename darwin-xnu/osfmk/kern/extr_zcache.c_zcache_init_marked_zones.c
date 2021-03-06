#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ cpu_cache_enable_when_ready; } ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 unsigned int num_zones ; 
 int /*<<< orphan*/  zcache_init (TYPE_1__*) ; 
 TYPE_1__* zone_array ; 

void zcache_init_marked_zones(void){
	unsigned int i;
	for(i = 0; i < num_zones; i ++){
		if(zone_array[i].cpu_cache_enable_when_ready){
			zcache_init(&zone_array[i]);
			zone_array[i].cpu_cache_enable_when_ready = FALSE;
		}
	}
}