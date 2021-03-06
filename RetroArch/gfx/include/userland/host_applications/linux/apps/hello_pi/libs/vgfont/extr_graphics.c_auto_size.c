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
typedef  scalar_t__ uint16_t ;

/* Variables and functions */
 scalar_t__ GRAPHICS_RESOURCE_WIDTH ; 

__attribute__((used)) static inline uint16_t auto_size(uint16_t arg, uint16_t actual_size)
{
   return arg == GRAPHICS_RESOURCE_WIDTH ? actual_size : arg;
}