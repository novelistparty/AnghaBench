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
typedef  int uint32 ;

/* Variables and functions */

__attribute__((used)) static uint32 swap_endianess(uint32 n)
{
    return ((n & 0xff) << 24) |
            ((n & 0xff00) << 8) |
            ((n & 0xff0000UL) >> 8) |
            ((n & 0xff000000UL) >> 24);
}