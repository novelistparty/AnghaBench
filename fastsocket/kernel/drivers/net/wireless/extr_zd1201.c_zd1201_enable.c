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
struct zd1201 {int mac_enabled; scalar_t__ monitor; } ;

/* Variables and functions */
 int /*<<< orphan*/  ZD1201_CMDCODE_ENABLE ; 
 int /*<<< orphan*/  ZD1201_RID_PROMISCUOUSMODE ; 
 int zd1201_docmd (struct zd1201*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int zd1201_setconfig16 (struct zd1201*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int zd1201_enable(struct zd1201 *zd)
{
	int err;

	if (zd->mac_enabled)
		return 0;

	err = zd1201_docmd(zd, ZD1201_CMDCODE_ENABLE, 0, 0, 0);
	if (!err)
		zd->mac_enabled = 1;

	if (zd->monitor)
		err = zd1201_setconfig16(zd, ZD1201_RID_PROMISCUOUSMODE, 1);

	return err;
}