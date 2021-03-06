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
struct frame_info {int dummy; } ;
struct alpha_mdebug_unwind_cache {scalar_t__ vfp; } ;
typedef  scalar_t__ CORE_ADDR ;

/* Variables and functions */
 int ALPHA_NUM_ARG_REGS ; 
 struct alpha_mdebug_unwind_cache* alpha_mdebug_frame_unwind_cache (struct frame_info*,void**) ; 

__attribute__((used)) static CORE_ADDR
alpha_mdebug_frame_args_address (struct frame_info *next_frame,
				 void **this_prologue_cache)
{
  struct alpha_mdebug_unwind_cache *info
    = alpha_mdebug_frame_unwind_cache (next_frame, this_prologue_cache);

  return info->vfp - ALPHA_NUM_ARG_REGS * 8;
}