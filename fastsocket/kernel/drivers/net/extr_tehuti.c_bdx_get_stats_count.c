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
typedef  int /*<<< orphan*/  u64 ;
struct net_device {int dummy; } ;
struct bdx_stats {int dummy; } ;
struct bdx_priv {scalar_t__ stats_flag; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BDX_ASSERT (int) ; 
 int /*<<< orphan*/  bdx_stat_names ; 
 struct bdx_priv* netdev_priv (struct net_device*) ; 

__attribute__((used)) static int bdx_get_stats_count(struct net_device *netdev)
{
	struct bdx_priv *priv = netdev_priv(netdev);
	BDX_ASSERT(ARRAY_SIZE(bdx_stat_names)
		   != sizeof(struct bdx_stats) / sizeof(u64));
	return ((priv->stats_flag) ? ARRAY_SIZE(bdx_stat_names)	: 0);
}