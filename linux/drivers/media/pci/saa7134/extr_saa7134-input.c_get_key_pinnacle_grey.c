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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct IR_i2c {int dummy; } ;
typedef  enum rc_proto { ____Placeholder_rc_proto } rc_proto ;

/* Variables and functions */
 int get_key_pinnacle (struct IR_i2c*,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int) ; 

__attribute__((used)) static int get_key_pinnacle_grey(struct IR_i2c *ir, enum rc_proto *protocol,
				 u32 *scancode, u8 *toggle)
{

	return get_key_pinnacle(ir, protocol, scancode, toggle, 1, 0xfe, 0xff);
}