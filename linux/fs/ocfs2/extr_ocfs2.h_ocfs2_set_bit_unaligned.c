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

/* Variables and functions */
 void* correct_addr_and_bit_unaligned (int*,void*) ; 
 int /*<<< orphan*/  ocfs2_set_bit (int,void*) ; 

__attribute__((used)) static inline void ocfs2_set_bit_unaligned(int bit, void *bitmap)
{
	bitmap = correct_addr_and_bit_unaligned(&bit, bitmap);
	ocfs2_set_bit(bit, bitmap);
}