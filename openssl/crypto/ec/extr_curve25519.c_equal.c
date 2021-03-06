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
typedef  int uint8_t ;
typedef  int uint32_t ;

/* Variables and functions */

__attribute__((used)) static uint8_t equal(signed char b, signed char c)
{
    uint8_t ub = b;
    uint8_t uc = c;
    uint8_t x = ub ^ uc; /* 0: yes; 1..255: no */
    uint32_t y = x;      /* 0: yes; 1..255: no */
    y -= 1;              /* 4294967295: yes; 0..254: no */
    y >>= 31;            /* 1: yes; 0: no */
    return y;
}