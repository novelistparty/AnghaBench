#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  content_icon; int /*<<< orphan*/  icon; } ;
typedef  TYPE_1__ xmb_node_t ;
struct TYPE_8__ {int /*<<< orphan*/  horizontal_list; } ;
typedef  TYPE_2__ xmb_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  MENU_LIST_HORIZONTAL ; 
 int /*<<< orphan*/  file_list_get_at_offset (int /*<<< orphan*/ ,unsigned int,char const**,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strstr (char const*,char*) ; 
 int /*<<< orphan*/  video_driver_texture_unload (int /*<<< orphan*/ *) ; 
 TYPE_1__* xmb_get_userdata_from_horizontal_list (TYPE_2__*,unsigned int) ; 
 size_t xmb_list_get_size (TYPE_2__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void xmb_context_destroy_horizontal_list(xmb_handle_t *xmb)
{
   unsigned i;
   size_t list_size = xmb_list_get_size(xmb, MENU_LIST_HORIZONTAL);

   for (i = 0; i < list_size; i++)
   {
      const char *path = NULL;
      xmb_node_t *node = xmb_get_userdata_from_horizontal_list(xmb, i);

      if (!node)
         continue;

      file_list_get_at_offset(xmb->horizontal_list, i,
            &path, NULL, NULL, NULL);

      if (!path || !strstr(path, ".lpl"))
         continue;

      video_driver_texture_unload(&node->icon);
      video_driver_texture_unload(&node->content_icon);
   }
}