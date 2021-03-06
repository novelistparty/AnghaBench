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

/* Variables and functions */
 int /*<<< orphan*/  get_v210 () ; 

__attribute__((used)) static void randomize_buffers(uint32_t *src0, uint32_t *src1, int len)
{
    for (int i = 0; i < len; i++) {
        uint32_t value = get_v210();
        src0[i] = value;
        src1[i] = value;
    }
}