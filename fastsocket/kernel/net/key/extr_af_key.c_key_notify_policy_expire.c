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
struct xfrm_policy {int dummy; } ;
struct km_event {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int key_notify_policy_expire(struct xfrm_policy *xp, struct km_event *c)
{
	return 0;
}