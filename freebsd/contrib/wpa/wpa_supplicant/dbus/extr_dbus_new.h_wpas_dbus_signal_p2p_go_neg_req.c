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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct wpa_supplicant {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void wpas_dbus_signal_p2p_go_neg_req(struct wpa_supplicant *wpa_s,
						   const u8 *src,
						   u16 dev_passwd_id,
						   u8 go_intent)
{
}