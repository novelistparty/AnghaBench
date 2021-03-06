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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  int32_t ;
struct TYPE_3__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
typedef  TYPE_1__* GRAPHICS_RESOURCE_HANDLE ;

/* Variables and functions */

int32_t graphics_get_resource_size(
   const GRAPHICS_RESOURCE_HANDLE res,
   uint32_t *w,
   uint32_t *h)
{
   if (w) *w = res->width;
   if (h) *h = res->height;
   return 0;
}