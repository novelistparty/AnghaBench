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
struct input_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/ * atari_input_mouse_interrupt_hook ; 
 int /*<<< orphan*/  ikbd_mouse_disable () ; 

__attribute__((used)) static void atamouse_close(struct input_dev *dev)
{
	ikbd_mouse_disable();
	atari_input_mouse_interrupt_hook = NULL;
}