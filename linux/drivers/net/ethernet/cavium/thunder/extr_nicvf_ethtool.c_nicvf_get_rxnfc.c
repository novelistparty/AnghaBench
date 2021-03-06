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
struct nicvf {int /*<<< orphan*/  rx_queues; } ;
struct net_device {int dummy; } ;
struct ethtool_rxnfc {int cmd; int /*<<< orphan*/  data; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
#define  ETHTOOL_GRXFH 129 
#define  ETHTOOL_GRXRINGS 128 
 struct nicvf* netdev_priv (struct net_device*) ; 
 int nicvf_get_rss_hash_opts (struct nicvf*,struct ethtool_rxnfc*) ; 

__attribute__((used)) static int nicvf_get_rxnfc(struct net_device *dev,
			   struct ethtool_rxnfc *info, u32 *rules)
{
	struct nicvf *nic = netdev_priv(dev);
	int ret = -EOPNOTSUPP;

	switch (info->cmd) {
	case ETHTOOL_GRXRINGS:
		info->data = nic->rx_queues;
		ret = 0;
		break;
	case ETHTOOL_GRXFH:
		return nicvf_get_rss_hash_opts(nic, info);
	default:
		break;
	}
	return ret;
}