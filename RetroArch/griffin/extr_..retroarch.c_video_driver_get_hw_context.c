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
struct retro_hw_render_callback {int dummy; } ;

/* Variables and functions */
 struct retro_hw_render_callback* video_driver_get_hw_context_internal () ; 

struct retro_hw_render_callback *video_driver_get_hw_context(void)
{
   return video_driver_get_hw_context_internal();
}