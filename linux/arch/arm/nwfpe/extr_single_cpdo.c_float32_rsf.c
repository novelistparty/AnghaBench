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
struct roundingData {int dummy; } ;
typedef  int /*<<< orphan*/  float32 ;

/* Variables and functions */
 int /*<<< orphan*/  float32_sub (struct roundingData*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static float32 float32_rsf(struct roundingData *roundData, float32 rFn, float32 rFm)
{
	return float32_sub(roundData, rFm, rFn);
}