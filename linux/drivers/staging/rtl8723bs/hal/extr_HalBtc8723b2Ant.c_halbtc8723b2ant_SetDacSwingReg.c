#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_4__ {int /*<<< orphan*/  (* fBtcWrite1ByteBitMask ) (TYPE_1__*,int,int,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__* PBTC_COEXIST ;

/* Variables and functions */
 int /*<<< orphan*/  ALGO_TRACE_SW_EXEC ; 
 int /*<<< orphan*/  BTC_MSG_ALGORITHM ; 
 int /*<<< orphan*/  BTC_PRINT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void halbtc8723b2ant_SetDacSwingReg(PBTC_COEXIST pBtCoexist, u32 level)
{
	u8 val = (u8)level;

	BTC_PRINT(
		BTC_MSG_ALGORITHM,
		ALGO_TRACE_SW_EXEC,
		("[BTCoex], Write SwDacSwing = 0x%x\n", level)
	);
	pBtCoexist->fBtcWrite1ByteBitMask(pBtCoexist, 0x883, 0x3e, val);
}