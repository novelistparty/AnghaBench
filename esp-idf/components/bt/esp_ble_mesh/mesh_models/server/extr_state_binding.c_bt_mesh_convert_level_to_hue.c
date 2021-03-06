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
typedef  int /*<<< orphan*/  u16_t ;
typedef  scalar_t__ s16_t ;

/* Variables and functions */
 scalar_t__ INT16_MIN ; 

u16_t bt_mesh_convert_level_to_hue(s16_t level)
{
    return (u16_t) (level - INT16_MIN);
}