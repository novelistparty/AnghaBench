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
typedef  int /*<<< orphan*/  u32 ;
struct mac_driver {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GMAC_AN_NEG_STATE_REG ; 
 int /*<<< orphan*/  GMAC_AN_NEG_STAT_RX_SYNC_OK_B ; 
 int /*<<< orphan*/  dsaf_get_dev_bit (struct mac_driver*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hns_gmac_get_link_status(void *mac_drv, u32 *link_stat)
{
	struct mac_driver *drv = (struct mac_driver *)mac_drv;

	*link_stat = dsaf_get_dev_bit(drv, GMAC_AN_NEG_STATE_REG,
				      GMAC_AN_NEG_STAT_RX_SYNC_OK_B);
}