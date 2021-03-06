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
struct adfs_discrecord {int /*<<< orphan*/  disc_size; int /*<<< orphan*/  disc_size_high; } ;

/* Variables and functions */
 int le32_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned long adfs_discsize(struct adfs_discrecord *dr, int block_bits)
{
	unsigned long discsize;

	discsize  = le32_to_cpu(dr->disc_size_high) << (32 - block_bits);
	discsize |= le32_to_cpu(dr->disc_size) >> block_bits;

	return discsize;
}