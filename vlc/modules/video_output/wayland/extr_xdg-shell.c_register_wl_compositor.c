#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {TYPE_2__* sys; } ;
typedef  TYPE_1__ vout_window_t ;
struct TYPE_4__ {int /*<<< orphan*/ * compositor; } ;
typedef  TYPE_2__ vout_window_sys_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct wl_registry {int dummy; } ;

/* Variables and functions */
 scalar_t__ likely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_compositor_interface ; 
 int /*<<< orphan*/ * wl_registry_bind (struct wl_registry*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void register_wl_compositor(void *data, struct wl_registry *registry,
                                   uint32_t name, uint32_t vers)
{
    vout_window_t *wnd = data;
    vout_window_sys_t *sys = wnd->sys;

    if (likely(sys->compositor == NULL))
        sys->compositor = wl_registry_bind(registry, name,
                                           &wl_compositor_interface, vers);
}