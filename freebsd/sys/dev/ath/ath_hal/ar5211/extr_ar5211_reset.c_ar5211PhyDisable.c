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
struct ath_hal {int dummy; } ;
typedef  int /*<<< orphan*/  HAL_BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  AR_RC_BB ; 
 int /*<<< orphan*/  ar5211SetResetReg (struct ath_hal*,int /*<<< orphan*/ ) ; 

HAL_BOOL
ar5211PhyDisable(struct ath_hal *ah)
{
	return ar5211SetResetReg(ah, AR_RC_BB);
}