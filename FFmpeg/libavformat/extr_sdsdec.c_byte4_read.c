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
typedef  scalar_t__ uint8_t ;
typedef  unsigned int uint32_t ;

/* Variables and functions */

__attribute__((used)) static void byte4_read(const uint8_t *src, uint32_t *dst)
{
    int i;

    for (i = 0; i < 120; i += 4) {
        unsigned sample;

        sample = ((unsigned)src[i + 0] << 25) | ((unsigned)src[i + 1] << 18) | ((unsigned)src[i + 2] << 11) | ((unsigned)src[i + 3] << 4);
        dst[i / 4] = sample;
    }
}