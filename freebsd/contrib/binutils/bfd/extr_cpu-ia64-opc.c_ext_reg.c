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
struct ia64_operand {TYPE_1__* field; } ;
typedef  unsigned int ia64_insn ;
struct TYPE_2__ {unsigned int shift; unsigned int bits; } ;

/* Variables and functions */

__attribute__((used)) static const char*
ext_reg (const struct ia64_operand *self, ia64_insn code, ia64_insn *valuep)
{
  *valuep = ((code >> self->field[0].shift)
	     & ((1u << self->field[0].bits) - 1));
  return 0;
}