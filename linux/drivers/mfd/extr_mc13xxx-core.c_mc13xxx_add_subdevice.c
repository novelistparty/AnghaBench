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
struct mc13xxx {int dummy; } ;

/* Variables and functions */
 int mc13xxx_add_subdevice_pdata (struct mc13xxx*,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mc13xxx_add_subdevice(struct mc13xxx *mc13xxx, const char *format)
{
	return mc13xxx_add_subdevice_pdata(mc13xxx, format, NULL, 0);
}