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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;

/* Variables and functions */

__attribute__((used)) static inline void rgb16to15_c(const uint8_t *src, uint8_t *dst, int src_size)
{
    register uint8_t *d         = dst;
    register const uint8_t *s   = src;
    register const uint8_t *end = s + src_size;
    const uint8_t *mm_end       = end - 3;

    while (s < mm_end) {
        register uint32_t x  = *((const uint32_t *)s);
        *((uint32_t *)d)     = ((x >> 1) & 0x7FE07FE0) | (x & 0x001F001F);
        s                   += 4;
        d                   += 4;
    }
    if (s < end) {
        register uint16_t x = *((const uint16_t *)s);
        *((uint16_t *)d)    = ((x >> 1) & 0x7FE0) | (x & 0x001F);
    }
}