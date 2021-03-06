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
struct TYPE_2__ {int /*<<< orphan*/  min_links; } ;
struct bonding {TYPE_1__ params; int /*<<< orphan*/  dev; } ;
struct bond_opt_value {int /*<<< orphan*/  value; } ;

/* Variables and functions */
 int /*<<< orphan*/  bond_set_carrier (struct bonding*) ; 
 int /*<<< orphan*/  netdev_dbg (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int bond_option_min_links_set(struct bonding *bond,
				     const struct bond_opt_value *newval)
{
	netdev_dbg(bond->dev, "Setting min links value to %llu\n",
		   newval->value);
	bond->params.min_links = newval->value;
	bond_set_carrier(bond);

	return 0;
}