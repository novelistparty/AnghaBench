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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  VP8LBitEntropy ;

/* Variables and functions */
 double BitsEntropyRefine (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  VP8LBitsEntropyUnrefined (int /*<<< orphan*/  const* const,int,int /*<<< orphan*/ *) ; 

double VP8LBitsEntropy(const uint32_t* const array, int n) {
  VP8LBitEntropy entropy;
  VP8LBitsEntropyUnrefined(array, n, &entropy);

  return BitsEntropyRefine(&entropy);
}