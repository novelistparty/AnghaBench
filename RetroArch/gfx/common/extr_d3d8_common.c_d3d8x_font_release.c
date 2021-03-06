#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* lpVtbl; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* Release ) (TYPE_2__*) ;} ;
typedef  TYPE_2__ ID3DXFont ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_2__*) ; 

void d3d8x_font_release(void *data)
{
#ifdef HAVE_D3DX
   ID3DXFont *font = (ID3DXFont*)data;
   if (font)
      font->lpVtbl->Release(font);
#endif
}