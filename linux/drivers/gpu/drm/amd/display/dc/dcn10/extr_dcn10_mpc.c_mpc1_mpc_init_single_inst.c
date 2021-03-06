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
struct mpc {int /*<<< orphan*/ * mpcc_array; } ;
struct dcn10_mpc {int dummy; } ;

/* Variables and functions */
 int MAX_OPP ; 
 int /*<<< orphan*/ * MPCC_BOT_SEL ; 
 int /*<<< orphan*/ * MPCC_OPP_ID ; 
 int /*<<< orphan*/ * MPCC_TOP_SEL ; 
 int /*<<< orphan*/  MPC_OUT_MUX ; 
 int /*<<< orphan*/ * MUX ; 
 scalar_t__ REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  REG_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct dcn10_mpc* TO_DCN10_MPC (struct mpc*) ; 
 int /*<<< orphan*/  mpc1_init_mpcc (int /*<<< orphan*/ *,unsigned int) ; 

void mpc1_mpc_init_single_inst(struct mpc *mpc, unsigned int mpcc_id)
{
	struct dcn10_mpc *mpc10 = TO_DCN10_MPC(mpc);
	int opp_id;

	REG_GET(MPCC_OPP_ID[mpcc_id], MPCC_OPP_ID, &opp_id);

	REG_SET(MPCC_TOP_SEL[mpcc_id], 0, MPCC_TOP_SEL, 0xf);
	REG_SET(MPCC_BOT_SEL[mpcc_id], 0, MPCC_BOT_SEL, 0xf);
	REG_SET(MPCC_OPP_ID[mpcc_id],  0, MPCC_OPP_ID,  0xf);

	mpc1_init_mpcc(&(mpc->mpcc_array[mpcc_id]), mpcc_id);

	if (opp_id < MAX_OPP && REG(MUX[opp_id]))
		REG_UPDATE(MUX[opp_id], MPC_OUT_MUX, 0xf);
}