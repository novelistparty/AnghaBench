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
typedef  enum a3xx_msaa_samples { ____Placeholder_a3xx_msaa_samples } a3xx_msaa_samples ;

/* Variables and functions */
 int A6XX_RB_RAS_MSAA_CNTL_SAMPLES__MASK ; 
 int A6XX_RB_RAS_MSAA_CNTL_SAMPLES__SHIFT ; 

__attribute__((used)) static inline uint32_t A6XX_RB_RAS_MSAA_CNTL_SAMPLES(enum a3xx_msaa_samples val)
{
	return ((val) << A6XX_RB_RAS_MSAA_CNTL_SAMPLES__SHIFT) & A6XX_RB_RAS_MSAA_CNTL_SAMPLES__MASK;
}