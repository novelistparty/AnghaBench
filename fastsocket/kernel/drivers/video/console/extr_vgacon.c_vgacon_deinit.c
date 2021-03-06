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
struct vc_data {int /*<<< orphan*/  vc_uni_pagedir; int /*<<< orphan*/ * vc_uni_pagedir_loc; int /*<<< orphan*/  vc_visible_origin; } ;

/* Variables and functions */
 scalar_t__ CON_IS_VISIBLE (struct vc_data*) ; 
 int /*<<< orphan*/  con_free_unimap (struct vc_data*) ; 
 int /*<<< orphan*/  con_set_default_unimap (struct vc_data*) ; 
 int /*<<< orphan*/  vga_set_mem_top (struct vc_data*) ; 
 int /*<<< orphan*/  vga_vram_base ; 
 int /*<<< orphan*/ * vgacon_uni_pagedir ; 

__attribute__((used)) static void vgacon_deinit(struct vc_data *c)
{
	/* When closing the active console, reset video origin */
	if (CON_IS_VISIBLE(c)) {
		c->vc_visible_origin = vga_vram_base;
		vga_set_mem_top(c);
	}

	if (!--vgacon_uni_pagedir[1])
		con_free_unimap(c);
	c->vc_uni_pagedir_loc = &c->vc_uni_pagedir;
	con_set_default_unimap(c);
}