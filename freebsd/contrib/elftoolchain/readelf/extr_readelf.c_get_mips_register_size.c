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

/* Variables and functions */

__attribute__((used)) static int
get_mips_register_size(uint8_t flag)
{
	switch (flag) {
	case 0: return 0;
	case 1: return 32;
	case 2: return 64;
	case 3: return 128;
	default: return -1;
	}
}