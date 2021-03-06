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
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  ASYNC_PF_PER_VCPU ; 
 int roundup_pow_of_two (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 kvm_async_pf_next_probe(u32 key)
{
	return (key + 1) & (roundup_pow_of_two(ASYNC_PF_PER_VCPU) - 1);
}