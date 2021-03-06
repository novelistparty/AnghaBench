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
typedef  size_t uint64_t ;
struct TYPE_2__ {char const* name; } ;

/* Variables and functions */
 TYPE_1__* cvmx_fpa_pool_info ; 

__attribute__((used)) static inline const char *cvmx_fpa_get_name(uint64_t pool)
{
    return cvmx_fpa_pool_info[pool].name;
}