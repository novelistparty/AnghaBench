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
struct x86emu {int /*<<< orphan*/  cur_rl; } ;

/* Variables and functions */
 int /*<<< orphan*/ * decode_rm_byte_register (struct x86emu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static uint8_t *
decode_rl_byte_register(struct x86emu *emu)
{
	return decode_rm_byte_register(emu, emu->cur_rl);
}