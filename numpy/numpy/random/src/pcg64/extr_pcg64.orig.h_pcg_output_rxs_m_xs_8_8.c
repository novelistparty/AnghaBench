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
typedef  unsigned int uint8_t ;

/* Variables and functions */

inline uint8_t pcg_output_rxs_m_xs_8_8(uint8_t state) {
  uint8_t word = ((state >> ((state >> 6u) + 2u)) ^ state) * 217u;
  return (word >> 6u) ^ word;
}