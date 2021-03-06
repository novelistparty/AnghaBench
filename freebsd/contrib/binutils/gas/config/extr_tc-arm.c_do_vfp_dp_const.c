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
struct TYPE_4__ {int instruction; TYPE_1__* operands; } ;
struct TYPE_3__ {int imm; int /*<<< orphan*/  reg; } ;

/* Variables and functions */
 int /*<<< orphan*/  VFP_REG_Dd ; 
 int /*<<< orphan*/  encode_arm_vfp_reg (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__ inst ; 

__attribute__((used)) static void
do_vfp_dp_const (void)
{
  encode_arm_vfp_reg (inst.operands[0].reg, VFP_REG_Dd);
  inst.instruction |= (inst.operands[1].imm & 0xf0) << 12;
  inst.instruction |= (inst.operands[1].imm & 0x0f);
}