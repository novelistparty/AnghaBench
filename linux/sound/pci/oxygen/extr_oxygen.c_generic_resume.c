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
struct oxygen {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ak4396_registers_init (struct oxygen*) ; 
 int /*<<< orphan*/  wm8785_registers_init (struct oxygen*) ; 

__attribute__((used)) static void generic_resume(struct oxygen *chip)
{
	ak4396_registers_init(chip);
	wm8785_registers_init(chip);
}