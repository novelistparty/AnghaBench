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
struct wps_uuid_pin {int /*<<< orphan*/  list; } ;

/* Variables and functions */
 int /*<<< orphan*/  dl_list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wps_free_pin (struct wps_uuid_pin*) ; 

__attribute__((used)) static void wps_remove_pin(struct wps_uuid_pin *pin)
{
	dl_list_del(&pin->list);
	wps_free_pin(pin);
}