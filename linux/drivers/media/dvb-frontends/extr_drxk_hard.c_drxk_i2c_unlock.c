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
struct drxk_state {int drxk_i2c_exclusive_lock; int /*<<< orphan*/  i2c; } ;

/* Variables and functions */
 int /*<<< orphan*/  I2C_LOCK_SEGMENT ; 
 int /*<<< orphan*/  i2c_unlock_bus (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void drxk_i2c_unlock(struct drxk_state *state)
{
	if (!state->drxk_i2c_exclusive_lock)
		return;

	i2c_unlock_bus(state->i2c, I2C_LOCK_SEGMENT);
	state->drxk_i2c_exclusive_lock = false;
}