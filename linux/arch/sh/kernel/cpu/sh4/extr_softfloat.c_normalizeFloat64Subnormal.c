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
typedef  int int8 ;
typedef  int int16 ;
typedef  int bits64 ;

/* Variables and functions */
 int countLeadingZeros64 (int) ; 

__attribute__((used)) static void
normalizeFloat64Subnormal(bits64 aSig, int16 * zExpPtr, bits64 * zSigPtr)
{
	int8 shiftCount;

	shiftCount = countLeadingZeros64(aSig) - 11;
	*zSigPtr = aSig << shiftCount;
	*zExpPtr = 1 - shiftCount;
}