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
typedef  int* xtensa_insnbuf ;
typedef  int uint32 ;

/* Variables and functions */

__attribute__((used)) static void
Field_combined3e2c5767_fld32xt_flix64_slot1_Slot_xt_flix64_slot1_set (xtensa_insnbuf insn, uint32 val)
{
  uint32 tie_t;
  tie_t = (val << 30) >> 30;
  insn[0] = (insn[0] & ~0x300) | (tie_t << 8);
  tie_t = (val << 24) >> 26;
  insn[0] = (insn[0] & ~0x3f000) | (tie_t << 12);
}