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
struct timing_generator {int dummy; } ;
struct optc {int dummy; } ;

/* Variables and functions */
 struct optc* DCN10TG_FROM_TG (struct timing_generator*) ; 
 int /*<<< orphan*/  OTG_BLANK_CONTROL ; 
 int /*<<< orphan*/  OTG_BLANK_DATA_EN ; 
 int /*<<< orphan*/  OTG_BLANK_DE_MODE ; 
 int /*<<< orphan*/  REG_UPDATE_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  optc1_clear_optc_underflow (struct timing_generator*) ; 

__attribute__((used)) static void optc1_unblank_crtc(struct timing_generator *optc)
{
	struct optc *optc1 = DCN10TG_FROM_TG(optc);

	REG_UPDATE_2(OTG_BLANK_CONTROL,
			OTG_BLANK_DATA_EN, 0,
			OTG_BLANK_DE_MODE, 0);

	/* W/A for automated testing
	 * Automated testing will fail underflow test as there
	 * sporadic underflows which occur during the optc blank
	 * sequence.  As a w/a, clear underflow on unblank.
	 * This prevents the failure, but will not mask actual
	 * underflow that affect real use cases.
	 */
	optc1_clear_optc_underflow(optc);
}