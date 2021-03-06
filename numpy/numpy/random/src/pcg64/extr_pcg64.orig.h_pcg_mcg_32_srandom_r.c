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
typedef  unsigned int uint32_t ;
struct pcg_state_32 {unsigned int state; } ;

/* Variables and functions */

inline void pcg_mcg_32_srandom_r(struct pcg_state_32 *rng, uint32_t initstate) {
  rng->state = initstate | 1u;
}