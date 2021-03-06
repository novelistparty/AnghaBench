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
struct bonding {int dummy; } ;
struct ad_info {int dummy; } ;

/* Variables and functions */
 int __bond_3ad_get_active_agg_info (struct bonding*,struct ad_info*) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 

int bond_3ad_get_active_agg_info(struct bonding *bond, struct ad_info *ad_info)
{
	int ret;

	rcu_read_lock();
	ret = __bond_3ad_get_active_agg_info(bond, ad_info);
	rcu_read_unlock();

	return ret;
}