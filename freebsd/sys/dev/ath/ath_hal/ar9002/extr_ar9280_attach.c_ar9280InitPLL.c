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
struct ieee80211_channel {int dummy; } ;
struct ath_hal {int dummy; } ;

/* Variables and functions */
 struct ieee80211_channel const* AH_NULL ; 
 int /*<<< orphan*/  AR_RTC_PLL_CONTROL ; 
 int /*<<< orphan*/  AR_RTC_SLEEP_CLK ; 
 int AR_RTC_SLEEP_DERIVED_CLK ; 
 int /*<<< orphan*/  AR_RTC_SOWL_PLL_CLKSEL ; 
 int /*<<< orphan*/  AR_RTC_SOWL_PLL_DIV ; 
 int /*<<< orphan*/  AR_RTC_SOWL_PLL_REFDIV ; 
 scalar_t__ AR_SREV_MERLIN_10_OR_LATER (struct ath_hal*) ; 
 scalar_t__ AR_SREV_MERLIN_20 (struct ath_hal*) ; 
 scalar_t__ IEEE80211_IS_CHAN_5GHZ (struct ieee80211_channel const*) ; 
 scalar_t__ IEEE80211_IS_CHAN_HALF (struct ieee80211_channel const*) ; 
 scalar_t__ IEEE80211_IS_CHAN_QUARTER (struct ieee80211_channel const*) ; 
 scalar_t__ IS_5GHZ_FAST_CLOCK_EN (struct ath_hal*,struct ieee80211_channel const*) ; 
 int /*<<< orphan*/  OS_DELAY (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OS_REG_WRITE (struct ath_hal*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  RTC_PLL_SETTLE_DELAY ; 
 int SM (int,int /*<<< orphan*/ ) ; 

void
ar9280InitPLL(struct ath_hal *ah, const struct ieee80211_channel *chan)
{
	uint32_t pll = SM(0x5, AR_RTC_SOWL_PLL_REFDIV);

	if (AR_SREV_MERLIN_20(ah) &&
	    chan != AH_NULL && IEEE80211_IS_CHAN_5GHZ(chan)) {
		/*
		 * PLL WAR for Merlin 2.0/2.1
		 * When doing fast clock, set PLL to 0x142c
		 * Else, set PLL to 0x2850 to prevent reset-to-reset variation 
		 */
		pll = IS_5GHZ_FAST_CLOCK_EN(ah, chan) ? 0x142c : 0x2850;
		if (IEEE80211_IS_CHAN_HALF(chan))
			pll |= SM(0x1, AR_RTC_SOWL_PLL_CLKSEL);
		else if (IEEE80211_IS_CHAN_QUARTER(chan))
			pll |= SM(0x2, AR_RTC_SOWL_PLL_CLKSEL);
	} else if (AR_SREV_MERLIN_10_OR_LATER(ah)) {
		pll = SM(0x5, AR_RTC_SOWL_PLL_REFDIV);
		if (chan != AH_NULL) {
			if (IEEE80211_IS_CHAN_HALF(chan))
				pll |= SM(0x1, AR_RTC_SOWL_PLL_CLKSEL);
			else if (IEEE80211_IS_CHAN_QUARTER(chan))
				pll |= SM(0x2, AR_RTC_SOWL_PLL_CLKSEL);
			if (IEEE80211_IS_CHAN_5GHZ(chan))
				pll |= SM(0x28, AR_RTC_SOWL_PLL_DIV);
			else
				pll |= SM(0x2c, AR_RTC_SOWL_PLL_DIV);
		} else
			pll |= SM(0x2c, AR_RTC_SOWL_PLL_DIV);
	}

	OS_REG_WRITE(ah, AR_RTC_PLL_CONTROL, pll);
	OS_DELAY(RTC_PLL_SETTLE_DELAY);
	OS_REG_WRITE(ah, AR_RTC_SLEEP_CLK, AR_RTC_SLEEP_DERIVED_CLK);
}