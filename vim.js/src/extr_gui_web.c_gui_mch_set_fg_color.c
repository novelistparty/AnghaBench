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
typedef  int /*<<< orphan*/  guicolor_T ;

/* Variables and functions */
 int /*<<< orphan*/  vimjs_set_fg_color (int /*<<< orphan*/ ) ; 

void
gui_mch_set_fg_color(guicolor_T color)
{
    vimjs_set_fg_color(color);
}