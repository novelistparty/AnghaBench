#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  gpio_cs; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpio_set_level (int /*<<< orphan*/ ,int) ; 
 TYPE_1__* s_slots ; 

__attribute__((used)) static void cs_high(int slot)
{
    gpio_set_level(s_slots[slot].gpio_cs, 1);
}