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
struct ocrdma_srq {unsigned int* idx_bit_fields; } ;

/* Variables and functions */

__attribute__((used)) static void ocrdma_srq_toggle_bit(struct ocrdma_srq *srq, int idx)
{
	int i = idx / 32;
	unsigned int mask = (1 << (idx % 32));

	if (srq->idx_bit_fields[i] & mask)
		srq->idx_bit_fields[i] &= ~mask;
	else
		srq->idx_bit_fields[i] |= mask;
}