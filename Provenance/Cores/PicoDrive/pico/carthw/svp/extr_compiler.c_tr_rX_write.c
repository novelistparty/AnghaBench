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
struct TYPE_2__ {int* r; } ;

/* Variables and functions */
 int /*<<< orphan*/  EOP_ADD_REG_LSL (int,int,int,int) ; 
 int /*<<< orphan*/  EOP_ADD_REG_LSR (int,int,int,int) ; 
 int /*<<< orphan*/  EOP_AND_IMM (int,int,int,int) ; 
 int /*<<< orphan*/  EOP_ORR_IMM (int,int,int,int) ; 
 int /*<<< orphan*/  EOP_STRH_SIMPLE (int /*<<< orphan*/ ,int) ; 
 int* hostreg_r ; 
 int known_regb ; 
 TYPE_1__ known_regs ; 
 int /*<<< orphan*/  tr_bank_write (int) ; 
 int /*<<< orphan*/  tr_ptrr_mod (int,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void tr_rX_write(int op)
{
	if ((op&3) == 3)
	{
		int mod = (op>>2) & 3; // direct addressing
		tr_bank_write((op & 0x100) + mod);
	}
	else
	{
		int r = (op&3) | ((op>>6)&4);
		if (known_regb & (1 << (r + 8))) {
			tr_bank_write((op&0x100) | known_regs.r[r]);
		} else {
			int reg = (r < 4) ? 8 : 9;
			int ror = ((4 - (r&3))*8) & 0x1f;
			EOP_AND_IMM(1,reg,ror/2,0xff);			// and r1, r{7,8}, <mask>
			if (r >= 4)
				EOP_ORR_IMM(1,1,((ror-8)&0x1f)/2,1);		// orr r1, r1, 1<<shift
			if (r&3) EOP_ADD_REG_LSR(1,7,1, (r&3)*8-1);	// add r1, r7, r1, lsr #lsr
			else     EOP_ADD_REG_LSL(1,7,1,1);
			EOP_STRH_SIMPLE(0,1);				// strh r0, [r1]
			hostreg_r[1] = -1;
		}
		tr_ptrr_mod(r, (op>>2) & 3, 0, 1);
	}
}