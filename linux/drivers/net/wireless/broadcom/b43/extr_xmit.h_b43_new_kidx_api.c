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
struct TYPE_2__ {int rev; } ;
struct b43_wldev {TYPE_1__ fw; } ;

/* Variables and functions */

__attribute__((used)) static inline int b43_new_kidx_api(struct b43_wldev *dev)
{
	/* FIXME: Not sure the change was at rev 351 */
	return (dev->fw.rev >= 351);
}