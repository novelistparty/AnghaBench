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
struct TYPE_2__ {int /*<<< orphan*/  thumbnail_path_data; } ;
typedef  TYPE_1__ xmb_handle_t ;

/* Variables and functions */
 scalar_t__ menu_thumbnail_get_system (int /*<<< orphan*/ ,char const**) ; 
 int /*<<< orphan*/  strlcpy (char*,char const*,size_t) ; 

__attribute__((used)) static void xmb_get_thumbnail_system(void *data, char*s, size_t len)
{
   xmb_handle_t *xmb  = (xmb_handle_t*)data;
   const char *system = NULL;
   if (!xmb)
      return;

   if (menu_thumbnail_get_system(xmb->thumbnail_path_data, &system))
      strlcpy(s, system, len);
}