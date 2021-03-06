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
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  Q68State ;

/* Variables and functions */
 int /*<<< orphan*/  INSN_GET_REG ; 
 int /*<<< orphan*/  JIT_EMIT_ADD_CYCLES (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  JIT_EMIT_GET_OP2_REGISTER (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  JIT_EMIT_MULS_W (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  JIT_EMIT_MULU_W (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  JIT_EMIT_SETCC_LOGIC_L (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  JIT_EMIT_SET_REGISTER_L (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SIZE_W ; 
 int cc_needed (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  current_entry ; 
 int /*<<< orphan*/  ea_get (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int reg ; 

__attribute__((used)) static int op_MUL(Q68State *state, uint32_t opcode)
{
    INSN_GET_REG;
    const int sign = opcode & (1<<8);

    int cycles;
    ea_get(state, opcode, SIZE_W, 0, &cycles, 1);
    if (cycles < 0) {
        return 1;
    }
    JIT_EMIT_GET_OP2_REGISTER(current_entry, reg*4);

    const int do_cc = cc_needed(state, opcode);
    if (sign) {
        JIT_EMIT_MULS_W(current_entry);
    } else {
        JIT_EMIT_MULU_W(current_entry);
    }
    /* 16*16 -> 32 multiplication can't produce carry or overflow, so we
     * can treat it like a logical operation for setting condition codes */
    if (do_cc) JIT_EMIT_SETCC_LOGIC_L(current_entry);
    JIT_EMIT_SET_REGISTER_L(current_entry, reg*4);

    JIT_EMIT_ADD_CYCLES(current_entry, 54 + cycles);
    return 0;
}