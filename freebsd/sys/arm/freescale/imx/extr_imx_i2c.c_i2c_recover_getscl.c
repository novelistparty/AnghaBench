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
struct i2c_softc {int /*<<< orphan*/  rb_sclpin; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpio_pin_is_active (int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static int
i2c_recover_getscl(void *ctx)
{
	bool active;

	gpio_pin_is_active(((struct i2c_softc *)ctx)->rb_sclpin, &active);
	return (active);

}