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
struct hwrng {int /*<<< orphan*/  (* cleanup ) (struct hwrng*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct hwrng*) ; 

__attribute__((used)) static inline void hwrng_cleanup(struct hwrng *rng)
{
	if (rng && rng->cleanup)
		rng->cleanup(rng);
}