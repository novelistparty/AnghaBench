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
typedef  int /*<<< orphan*/  int32_t ;
struct TYPE_3__ {scalar_t__ evenspill; } ;
typedef  TYPE_1__ ASMState ;

/* Variables and functions */
 scalar_t__ SPS_FIXED ; 
 int /*<<< orphan*/  sps_align (scalar_t__) ; 
 int /*<<< orphan*/  sps_scale (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int32_t asm_stack_adjust(ASMState *as)
{
  if (as->evenspill <= SPS_FIXED)
    return 0;
  return sps_scale(sps_align(as->evenspill));
}