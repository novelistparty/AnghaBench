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

/* Variables and functions */
 int /*<<< orphan*/  RGBA8 (int,int,int,int) ; 
 int /*<<< orphan*/  vita2d_set_clear_color (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void menu_display_vita2d_restore_clear_color(void)
{
   vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
}