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
typedef  int /*<<< orphan*/  u64 ;
struct spu {int /*<<< orphan*/ * shadow_int_mask_RW; } ;

/* Variables and functions */

__attribute__((used)) static inline u64 _int_mask_get(struct spu *spu, int class)
{
	return spu->shadow_int_mask_RW[class];
}