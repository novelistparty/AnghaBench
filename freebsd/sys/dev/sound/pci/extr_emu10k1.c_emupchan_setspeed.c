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
typedef  int /*<<< orphan*/  u_int32_t ;
struct sc_pchinfo {int /*<<< orphan*/  spd; } ;
typedef  int /*<<< orphan*/  kobj_t ;

/* Variables and functions */

__attribute__((used)) static u_int32_t
emupchan_setspeed(kobj_t obj, void *data, u_int32_t speed)
{
	struct sc_pchinfo *ch = data;

	ch->spd = speed;
	return ch->spd;
}