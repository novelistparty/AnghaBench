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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct TYPE_2__ {int /*<<< orphan*/  R_CL; } ;
struct x86emu {TYPE_1__ x86; } ;

/* Variables and functions */
 int /*<<< orphan*/  decode_and_fetch_word (struct x86emu*) ; 
 int /*<<< orphan*/  decode_and_fetch_word_imm8 (struct x86emu*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * decode_rh_word_register (struct x86emu*) ; 
 int /*<<< orphan*/  fetch_decode_modrm (struct x86emu*) ; 
 int /*<<< orphan*/  shld_word (struct x86emu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  shrd_word (struct x86emu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write_back_word (struct x86emu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
common_shift16(struct x86emu *emu, int shift_left, int use_cl)
{
	uint8_t shift;
	uint16_t destval, *shiftreg;

	fetch_decode_modrm(emu);
	shiftreg = decode_rh_word_register(emu);
	if (use_cl) {
		destval = decode_and_fetch_word(emu);
		shift = emu->x86.R_CL;
	} else {
		destval = decode_and_fetch_word_imm8(emu, &shift);
	}
	if (shift_left)
		destval = shld_word(emu, destval, *shiftreg, shift);
	else
		destval = shrd_word(emu, destval, *shiftreg, shift);
	write_back_word(emu, destval);
}