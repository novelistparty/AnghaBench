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
typedef  size_t u8 ;
struct adv748x_state {int /*<<< orphan*/ * regmap; } ;

/* Variables and functions */
 int regmap_write (int /*<<< orphan*/ ,size_t,size_t) ; 

int adv748x_write(struct adv748x_state *state, u8 page, u8 reg, u8 value)
{
	return regmap_write(state->regmap[page], reg, value);
}