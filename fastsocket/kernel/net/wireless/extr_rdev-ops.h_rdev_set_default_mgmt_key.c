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
typedef  int /*<<< orphan*/  u8 ;
struct net_device {int dummy; } ;
struct cfg80211_registered_device {int /*<<< orphan*/  wiphy; TYPE_1__* ops; } ;
struct TYPE_2__ {int (* set_default_mgmt_key ) (int /*<<< orphan*/ *,struct net_device*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ *,struct net_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_rdev_return_int (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  trace_rdev_set_default_mgmt_key (int /*<<< orphan*/ *,struct net_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int
rdev_set_default_mgmt_key(struct cfg80211_registered_device *rdev,
			  struct net_device *netdev, u8 key_index)
{
	int ret;
	trace_rdev_set_default_mgmt_key(&rdev->wiphy, netdev, key_index);
	ret = rdev->ops->set_default_mgmt_key(&rdev->wiphy, netdev,
					       key_index);
	trace_rdev_return_int(&rdev->wiphy, ret);
	return ret;
}