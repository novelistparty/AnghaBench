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
struct TYPE_2__ {int sec; int usec; } ;
struct wpa_supplicant {TYPE_1__ roam_time; } ;
struct wpa_dbus_property_desc {int dummy; } ;
typedef  int dbus_uint32_t ;
typedef  int /*<<< orphan*/  dbus_bool_t ;
typedef  int /*<<< orphan*/  DBusMessageIter ;
typedef  int /*<<< orphan*/  DBusError ;

/* Variables and functions */
 int /*<<< orphan*/  DBUS_TYPE_UINT32 ; 
 int /*<<< orphan*/  wpas_dbus_simple_property_getter (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ *) ; 

dbus_bool_t wpas_dbus_getter_roam_time(
	const struct wpa_dbus_property_desc *property_desc,
	DBusMessageIter *iter, DBusError *error, void *user_data)
{
	struct wpa_supplicant *wpa_s = user_data;
	dbus_uint32_t roam_time = wpa_s->roam_time.sec * 1000 +
		wpa_s->roam_time.usec / 1000;

	return wpas_dbus_simple_property_getter(iter, DBUS_TYPE_UINT32,
						&roam_time, error);
}