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
struct wpa_authenticator {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline int wpa_auth_get_seqnum(struct wpa_authenticator *wpa_auth,
                      const u8 *addr, int idx, u8 *seq)
{
    return -1;
}