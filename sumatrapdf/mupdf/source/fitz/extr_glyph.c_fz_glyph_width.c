#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int w; } ;
typedef  TYPE_1__ fz_glyph ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */

int
fz_glyph_width(fz_context *ctx, fz_glyph *glyph)
{
	return glyph->w;
}